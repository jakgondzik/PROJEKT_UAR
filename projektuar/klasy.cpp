#include "klasy.h"
#include <iostream>
#include <deque>
#include <array>
#include <random>
#include <cmath>

using namespace std;

class Symulacja
{
protected:
	//Nazwy pisze na szybko, do sprawdzenia
	unique_ptr<ARX> m_ARX;
	unique_ptr<PID> m_PID;
	double m_zadane;
	double m_zmierzone;
public:
	//Musze sprawdzic jak sie wyklucza konstruktor domyslny
	void wykonajKrok()
	{
		//Sprawdzenie czy arx i pid sa ustawione
		// do dopisania w czwartek
	}
	Symulacja() = delete; // wykluczylem konstruktor domyslny
	Symulacja(unique_ptr<ARX> arx, unique_ptr<PID> pid)
		: m_ARX(move(arx)), m_PID(move(pid)), m_zmierzone(0.0) {}
	/*void setARX(ARX* arx)
	{
		if(arx != nullptr)
		{
			m_ARX = arx;
		}
		else
		{
			throw invalid_argument("Nie podales modelu!!!");
		}
	}
	void setPID(PID * pid)
		{
			if(pid != nullptr)
			{
				m_PID = pid;
			}
			else
			{
				throw invalid_argument("Nie podales regulatora!!!");
			}
		}*/
	void setZadane(double zadane)
	{
		m_zadane = zadane;
	}
	double krok()
	{
		double sygnal = m_PID->oblicz(m_zadane, m_zmierzone);
		m_zmierzone = m_ARX->krok(sygnal);
		return m_zmierzone;
	}
	void reset()
	{
		m_PID->reset();
		m_ARX->reset();
		m_zmierzone = 0.0;
	}
};
class ARX
{
protected:
	deque<double> m_yi = { 0 };
	vector<double> m_vec_a;
	vector<double> m_vec_b;
	//tymczasowo tak iteracje bo trzeba przerobic pod QTIMER, ewentualnie mo¿emy statycznie to zrobiæ
	int m_iteracje = 0;
	int m_delay = 0;
	double m_zaklocenia;
	deque<double> m_ui;
	default_random_engine generator;
	normal_distribution<double> gzaklocen;

	//zaklocenia beda losowane
public:
	double wykonajKrok()
	{
		double y = m_vec_b[0] * m_ui.back() + m_vec_b[1] * m_ui.back() - m_vec_a[0] * m_yi.front() + m_vec_a[1] * m_yi.front();
		m_yi.push_front(y);
		czyJuz();
	}
	double krok(double u) //inna wersja kroku
	{
		m_ui.push_back(u);
		if (m_ui.size() > m_vec_b.size() + m_delay)
		{
			m_ui.pop_front();
		}
		double wyjscie = 0.0;

		for (size_t i = 0; i < m_vec_b.size(); i++)
		{
			wyjscie += m_vec_b[i] * m_ui[m_ui.size() - 1 - i - m_delay];
		}

		for (size_t i = 0; i < m_vec_b.size(); i++)
		{
			wyjscie -= m_vec_a[i] * m_yi[m_yi.size() - 1 - i];
		}

		if (m_zaklocenia > 0.0)
		{
			wyjscie += gzaklocen(generator);
		}

		m_yi.push_back(wyjscie);
		if (m_yi.size() > m_vec_a.size())
		{
			m_yi.pop_front();
		}
		return wyjscie;
	}
	void setZaklocenia(double zaklocenia) //nowa wartosc dla uchybu zaklocen
	{
		m_zaklocenia = zaklocenia;
		gzaklocen = normal_distribution<double>(0.0, zaklocenia);
	}
	void czyJuz()
	{
		m_iteracje++;
		m_delay--;
		if (m_delay == 0)
		{
			m_ui.pop_back();
		}
	}
	ARX(const vector<double>& vec_a, const vector<double>& vec_b, int delay, int iteracje, double zaklocenia = 0.0)
		:m_ui(deque<double>(vec_b.size() + delay, 0.0)), m_yi(deque<double>(vec_a.size(), 0.0)), gzaklocen(0.0, zaklocenia) {
		setVektory(vec_a, vec_b);
		setIteracje(iteracje);
		setDelay(delay);
	}
	void setZadane(deque<double> u)
	{
		double najmniejsza = 1000000;
		if (*(std::find(u.begin(), u.end(), najmniejsza)) < 0)
		{
			throw invalid_argument("sygnal zadany nie moze byc ujemny...");
		}
		else
		{
			m_ui = u;
		}
	}
	void setSkok(double skok)
	{
		//nie jestem troche pewny co do tego
		if (skok < 0) { throw invalid_argument("Wartosc jest niepoprawna"); }
		m_ui.push_front(skok);
	}
	void setVektory(vector<double> vec_a, vector<double> vec_b)
	{
		//trzeba dopisac zabezpieczenia, chociaz ja zadnych nie widze
		m_vec_a = vec_a;
		m_vec_b = vec_b;
	}
	void setIteracje(int i)
	{
		if (i <= 0) { throw invalid_argument("nie wykonujesz obliczen"); }
		m_iteracje = i;
	}
	void setDelay(int k)
	{
		if (k < 0) { throw invalid_argument("Wartosc jest niepoprawna"); }
		m_delay = k;
	}
	void reset()
	{
		fill(m_ui.begin(), m_ui.end(), 0.0);
		fill(m_yi.begin(), m_yi.end(), 0.0);
	}
};

class PID
{
protected:
	double m_kp;
	double m_ti;
	double m_td;
	double m_suma;
	double m_pop_blad;
	bool m_resetI;

public:
	PID(double p, double i, double d)
		:m_kp(p), m_ti(i), m_td(d), m_suma(0.0), m_pop_blad(0.0) {}

	double oblicz(double cel, double zmierzone)
	{
		double blad = cel - zmierzone;
		double P = m_kp * blad;

		m_suma += blad;
		double I;
		if (m_ti == 0.0)
		{
			I = 0.0;
		}
		else {
			I = m_suma / m_ti;
		}

		double D = m_td * (blad - m_pop_blad);

		return P + I + D;
	}

	void reset()
	{
		m_pop_blad = 0.0;
		m_suma = 0.0;
	}

	void setParametry(double kp, double ti, double td)
	{
		m_kp = kp;
		m_ti = ti;
		m_td = td;
	}

	void wylaczResetI(bool wlaczone)
	{
		m_resetI = wlaczone;
		if (wlaczone)
		{
			m_suma = 0.0;
		}
	}
};

class WartoscZadana {
protected:
	TypSygnalu m_typsygnalu;
	double m_amplituda;
	double m_okres;
	double m_cykl;
	int m_aktywacja;
	int m_czas;
public:
	WartoscZadana() : m_typsygnalu(skok), m_amplituda(1.0), m_okres(1.0), m_cykl(0.5), m_aktywacja(0), m_czas(0) {}
	void ustawskok(double amplituda, int aktywacja)
	{
		m_typsygnalu = skok;
		m_amplituda = amplituda;
		m_aktywacja = aktywacja;
	}
	void ustawsinusoide(double amplituda, double okres)
	{
		m_typsygnalu = sinusoida;
		m_amplituda = amplituda;
		m_okres = okres;
	}
	void ustawprostokatny(double amplituda, double okres, double cykl)
	{
		m_typsygnalu = prostokatny;
		m_amplituda = amplituda;
		m_okres = okres;
		m_cykl = cykl;
	}
	double generuj()
	{
		double wartosc = 0.0;

		switch (m_typsygnalu) {
		case skok:
			if (m_czas >= m_aktywacja)
			{
				wartosc = m_amplituda;
			}
			else {
				wartosc = 0.0;
			}
			break;
		case sinusoida:
			wartosc = m_amplituda * sin(2 * 3.14 * (m_czas % static_cast<int>(m_okres)) / m_okres);
			break;
		case prostokatny:
			if ((m_czas % static_cast<int>(m_okres)) < (m_cykl * m_okres))
			{
				wartosc = m_amplituda;
			}
			else {
				m_amplituda = 0.0;
			}
			break;
		}
		m_czas++;
		return wartosc;
	}
	void reset()
	{
		m_czas = 0;
	}
};
