#include "klasy.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>

	void Symulacja::setZadane(double zadane)
	{
		m_zadane = zadane;
	}
	double Symulacja::krok()
	{
		if (!m_ARX || !m_PID)
		{
			throw std::logic_error("Nie ustawiono ARX lub PID");
		}
		double sygnal = m_PID->oblicz(m_zadane, m_zmierzone);
		m_zmierzone = m_ARX->krok(sygnal);
		return m_zmierzone;
	}
	void Symulacja::reset()
	{
		m_PID->reset();
		m_ARX->reset();
		m_zmierzone = 0.0;
	}

	/*double ARX::wykonajKrok()
	{
		double y = m_vec_b[0] * m_ui.back() + m_vec_b[1] * m_ui.back() - m_vec_a[0] * m_yi.front() + m_vec_a[1] * m_yi.front();
		m_yi.push_front(y);
		czyJuz();
	}*/
	double ARX::krok(double u) //inna wersja kroku
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
	void ARX::setZaklocenia(double zaklocenia) //nowa wartosc dla uchybu zaklocen
	{
		m_zaklocenia = zaklocenia;
		gzaklocen = std::normal_distribution<double>(0.0, zaklocenia);
	}
	/*void ARX::czyJuz()
	{
		m_iteracje++;
		m_delay--;
		if (m_delay == 0)
		{
			m_ui.pop_back();
		}
	}*/
	ARX::ARX(const std::vector<double>& vec_a, const std::vector<double>& vec_b, int delay, int iteracje, double zaklocenia)
		:m_ui(std::deque<double>(vec_b.size() + delay, 0.0)), m_yi(std::deque<double>(vec_a.size(), 0.0)), gzaklocen(0.0, zaklocenia) {
		setVektory(vec_a, vec_b);
		setIteracje(iteracje);
		setDelay(delay);
	}
	/*void ARX::setZadane(std::deque<double> u)
	{
		double najmniejsza = 1000000;
		if (*(std::find(u.begin(), u.end(), najmniejsza)) < 0)
		{
			throw std::invalid_argument("sygnal zadany nie moze byc ujemny...");
		}
		else
		{
			m_ui = u;
		}
	}*/
	/*void ARX::setSkok(double skok)
	{
		//nie jestem troche pewny co do tego
		if (skok < 0) { throw std::invalid_argument("Wartosc jest niepoprawna"); }
		m_ui.push_front(skok);
	}*/
	void ARX::setVektory(std::vector<double> vec_a, std::vector<double> vec_b)
	{
		//trzeba dopisac zabezpieczenia, chociaz ja zadnych nie widze
		m_vec_a = vec_a;
		m_vec_b = vec_b;
	}
	void ARX::setIteracje(int i)
	{
		if (i <= 0) { throw std::invalid_argument("nie wykonujesz obliczen"); }
		m_iteracje = i;
	}
	void ARX::setDelay(int k)
	{
		if (k < 0) { throw std::invalid_argument("Wartosc jest niepoprawna"); }
		m_delay = k;
	}
	void ARX::reset()
	{
		fill(m_ui.begin(), m_ui.end(), 0.0);
		fill(m_yi.begin(), m_yi.end(), 0.0);
	}



	PID::PID(double p, double i, double d)
		:m_kp(p), m_ti(i), m_td(d), m_suma(0.0), m_pop_blad(0.0), m_resetI(false) {}

	double PID::oblicz(double cel, double zmierzone)
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
			I = (m_suma / m_ti);
		}

		double D = m_td * (blad - m_pop_blad);
		m_pop_blad = blad;

		return P + I + D;
	}

	void PID::reset()
	{
		m_pop_blad = 0.0;
		m_suma = 0.0;
	}

	void PID::setParametry(double kp, double ti, double td)
	{
		m_kp = kp;
		m_ti = ti;
		m_td = td;
	}

	void PID::wylaczResetI(bool wlaczone)
	{
		m_resetI = wlaczone;
		if (wlaczone)
		{
			m_suma = 0.0;
		}
	}


	WartoscZadana::WartoscZadana() : m_typsygnalu(skok), m_amplituda(1.0), m_okres(1.0), m_cykl(0.5), m_aktywacja(0), m_czas(0) {}
	void WartoscZadana::ustawskok(double amplituda, int aktywacja)
	{
		m_typsygnalu = skok;
		m_amplituda = amplituda;
		m_aktywacja = aktywacja;
	}
	void WartoscZadana::ustawsinusoide(double amplituda, double okres)
	{
		m_typsygnalu = sinusoida;
		m_amplituda = amplituda;
		m_okres = okres;
	}
	void WartoscZadana::ustawprostokatny(double amplituda, double okres, double cykl)
	{
		m_typsygnalu = prostokatny;
		m_amplituda = amplituda;
		m_okres = okres;
		m_cykl = cykl;
	}
	double WartoscZadana::generuj()
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
	void WartoscZadana::reset()
	{
		m_czas = 0;
	}

