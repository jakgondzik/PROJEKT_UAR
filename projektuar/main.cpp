#include <iostream>
#include <deque>
#include <array>
#include <random>
#include <cmath>
/*
TODO:
ARX:



PID:




*/
using namespace std;
class Symulacja
{
protected:
	//Nazwy pisze na szybko, do sprawdzenia
	ARX * m_ARX = nullptr;
	PID * m_PID = nullptr;
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
	Symulacja(ARX* arx, PID * pid, double zadane)
	{
		setARX(arx);
		setPID(pid);
		setZadane(zadane);
	}
	void setARX(ARX * arx)
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
		}
	void setZadane(double zadane)
	{
		m_zadane = zadane;
	}
	double krok()
	{
		double sygnal = m_PID->oblicz(m_zadane, m_zmierzone);

		//dokonczyc!!!!!!!!!!!!!!
	}
};
class ARX
{
protected:
	deque<double> m_yi = { 0 };
	array<double, 2> m_vec_a;
	array<double, 2> m_vec_b;
	//tymczasowo tak iteracje bo trzeba przerobic pod QTIMER, ewentualnie możemy statycznie to zrobić
	int m_iteracje = 0;
	int m_delay = 0;
	deque<double> m_ui;

	//zaklocenia beda losowane
public:
	double wykonajKrok()
	{
		double y = m_vec_b[0] * m_ui.back() + m_vec_b[1] * m_ui.back() - m_vec_a[0] * m_yi.front() + m_vec_a[1] * m_yi.front();
		m_yi.push_front(y);
		czyJuz();
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
	ARX(array<double, 2> vec_a, array<double, 2> vec_b, int delay, int iteracje)
	{
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
	void setVektory(array<double, 2> vec_a, array<double, 2> vec_b)
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
};

class PID
{
protected:
	double m_kp;
	double m_ki;
	double m_kd;
	double m_suma;
	double m_pop_blad;

public:
	PID(double p, double i, double d)
		:m_kp(p), m_ki(i), m_kd(d), m_suma(0.0), m_pop_blad(0.0) {}

	double oblicz(double cel, double zmierzone)
	{
		double blad = cel - zmierzone;
		double P = m_kp * blad;

		m_suma += blad;
		double I;
		if (m_ki == 0.0)
		{
			I = 0.0;
		}
		else {
			I = m_suma / m_ki;
		}

		double D = m_kd * (blad - m_pop_blad);

		return P + I + D;
	}

};

enum TypSygnalu {skok, sinusoida, prostokatny};

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

int main()
{
	deque<int> yi = { 1,2,3,4 };
	cout << yi[2];
}
