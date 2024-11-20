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
public:
	//Musze sprawdzic jak sie wyklucza konstruktor domyslny
	void wykonajKrok()
	{
		//Sprawdzenie czy arx i pid sa ustawione
		// do dopisania w czwartek
	}
	Symulacja() = delete[]; // wykluczylem konstruktor domyslny
	Symulacja(ARX* arx, PID * pid)
	{
		setARX(arx);
		setPID(pid);
	}
	void setARX(ARX * arx)
	{
		if(arx != nullptr)
		{
			m_arx = arx;
		}
		else
		{
			throw invalid_argument("Nie podales regulatora!!!");
		}
	}
	void setPID(PID * pid)
		{
			if(pid != nullptr)
			{
				m_pid = pid;
			}
			else
			{
				throw invalid_argument("Nie podales ukladu czegos tam dopiszemy!!!");
			}
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
	double kp;
	double ki;
	double kd;
	double suma;
	double pop_blad;

public:
	PID(double p, double i, double d)
		:kp(p), ki(i), kd(d), suma(0.0), pop_blad(0.0) {}

	double oblicz(double cel, double zmierzone)
	{
		double blad = cel - zmierzone;
		double P = kp * blad;

		suma += blad;
		double I;
		if (ki == 0.0)
		{
			I = 0.0;
		}
		else {
			I = suma / ki;
		}

		double D = kd * (blad - pop_blad);

		return P + I + D;
	}

};

int main()
{
	deque<int> yi = { 1,2,3,4 };
	cout << yi[2];
}
