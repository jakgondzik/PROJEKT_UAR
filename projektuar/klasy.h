#pragma once
#include <iostream>
#include <deque>
#include <vector>
#include <array>
#include <random>
#include <memory>
#include <cmath>
#include <stdexcept>

class Symulacja
{
protected:
	//Nazwy pisze na szybko, do sprawdzenia
	std::unique_ptr<class ARX> m_ARX;
	std::unique_ptr<class PID> m_PID;
	double m_zadane;
	double m_zmierzone;
public:
	//Musze sprawdzic jak sie wyklucza konstruktor domyslny
	//void wykonajKrok();
	Symulacja() = delete; // wykluczylem konstruktor domyslny
	Symulacja(std::unique_ptr<ARX> arx, std::unique_ptr<PID> pid)
		: m_ARX(std::move(arx)), m_PID(std::move(pid)), m_zadane(0.0), m_zmierzone(0.0) {}
	void setZadane(double zadane);
	double krok();
	void reset();
};
	class ARX
	{
	protected:
		std::deque<double> m_yi;
		std::vector<double> m_vec_a;
		std::vector<double> m_vec_b;
		//tymczasowo tak iteracje bo trzeba przerobic pod QTIMER, ewentualnie mo¿emy statycznie to zrobiæ
		int m_iteracje;
		int m_delay;
		double m_zaklocenia;
		std::deque<double> m_ui;
		std::default_random_engine generator;
		std::normal_distribution<double> gzaklocen;

		//zaklocenia beda losowane
	public:
		//double wykonajKrok();
		double krok(double u);
		void setZaklocenia(double zaklocenia);
		//void czyJuz();
		ARX(const std::vector<double>& vec_a, const std::vector<double>& vec_b, int delay, int iteracje, double zaklocenia = 0.0);
		//void setZadane(std::deque<double> u);
		//void setSkok(double skok);
		void setVektory(std::vector<double> vec_a, std::vector<double> vec_b);
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