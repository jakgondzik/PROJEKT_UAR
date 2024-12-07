#pragma once
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
	void wykonajKrok();
	Symulacja() = delete; // wykluczylem konstruktor domyslny
	Symulacja(unique_ptr<ARX> arx, unique_ptr<PID> pid);
	void setZadane(double zadane);
	double krok();
	void reset();
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
		double wykonajKrok();
		double krok(double u);
		void setZaklocenia(double zaklocenia);
		void czyJuz();
		ARX(const vector<double>& vec_a, const vector<double>& vec_b, int delay, int iteracje, double zaklocenia = 0.0);
		void setZadane(deque<double> u);
		void setSkok(double skok);
		void setVektory(vector<double> vec_a, vector<double> vec_b);
		void setIteracje(int i);
		void setDelay(int k);
		void reset();
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
		PID(double p, double i, double d);
		double oblicz(double cel, double zmierzone);
		void reset();
		void setParametry(double kp, double ti, double td);
		void wylaczResetI(bool wlaczone);
	};

	enum TypSygnalu { skok, sinusoida, prostokatny };

	class WartoscZadana {
	protected:
		TypSygnalu m_typsygnalu;
		double m_amplituda;
		double m_okres;
		double m_cykl;
		int m_aktywacja;
		int m_czas;
	public:
		WartoscZadana();
		void ustawskok(double amplituda, int aktywacja);
		void ustawsinusoide(double amplituda, double okres);
		void ustawprostokatny(double amplituda, double okres, double cykl);
		double generuj();
		void reset();
	};