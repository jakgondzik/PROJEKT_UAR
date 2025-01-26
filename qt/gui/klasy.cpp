#include "klasy.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>

// ---------------------- ARX ----------------------
ARX::ARX(const std::vector<double>& vec_a, const std::vector<double>& vec_b, int delay, double zaklocenia)
    : m_ui(std::deque<double>(vec_b.size() + delay, 0.0)), m_yi(std::deque<double>(vec_a.size(), 0.0)), gzaklocen(0.0, zaklocenia) {
    setVektory(vec_a, vec_b);
    setDelay(delay);
    m_zaklocenia = zaklocenia;
}

double ARX::krok(double u) {
    m_ui.push_back(u);
    if (m_ui.size() > m_vec_b.size() + m_delay) m_ui.pop_front();

    double wyjscie = 0.0;
    for (size_t i = 0; i < m_vec_b.size(); i++) {
        wyjscie += m_vec_b[i] * m_ui[m_ui.size() - 1 - i - m_delay];
    }
    for (size_t i = 0; i < m_vec_a.size(); i++) {
        wyjscie -= m_vec_a[i] * m_yi[m_yi.size() - 1 - i];
    }
    if (m_zaklocenia > 0.0) wyjscie += gzaklocen(generator);

    m_yi.push_back(wyjscie);
    if (m_yi.size() > m_vec_a.size()) m_yi.pop_front();

    return wyjscie;
}

void ARX::setVektory(const std::vector<double>& vec_a, const std::vector<double>& vec_b) {
    if (vec_a.empty() || vec_b.empty()) {
        throw std::invalid_argument("Wektory A i B nie mog¹ byæ puste.");
    }
    m_vec_a = vec_a;
    m_vec_b = vec_b;
    reset();
}

void ARX::setDelay(int delay) {
    if (delay < 1) {
        throw std::invalid_argument("OpóŸnienie musi byæ wiêksze od 0.");
    }
    m_delay = delay;
}

void ARX::setZaklocenia(double zaklocenia) {
    if (zaklocenia < 0.0) {
        throw std::invalid_argument("Zak³ócenia musz¹ byæ wiêksze lub równe 0.");
    }
    m_zaklocenia = zaklocenia;
    gzaklocen = std::normal_distribution<double>(0.0, zaklocenia);
}

void ARX::reset() {
    std::fill(m_ui.begin(), m_ui.end(), 0.0);
    std::fill(m_yi.begin(), m_yi.end(), 0.0);
}

// ---------------------- PID ----------------------
PID::PID(double p, double i, double d) : m_kp(p), m_ti(i), m_td(d), m_suma(0.0), m_pop_blad(0.0) {}

double PID::obliczP(double cel, double zmierzone)
{
    double blad = cel - zmierzone;
    m_suma += blad;
    return m_kp * blad;
}

double PID::obliczI()
{
    return (m_ti == 0.0) ? 0.0 : (m_suma / m_ti);
}

double PID::obliczD(double cel, double zmierzone)
{
    double blad = cel - zmierzone;
    double D = m_td * (blad - m_pop_blad);
    m_pop_blad = blad;
    return D;
}

double PID::oblicz(double cel, double zmierzone)
{    
    return obliczP(cel, zmierzone) + obliczI() + obliczD(cel, zmierzone);
}

void PID::reset() {
    m_suma = 0.0;
    m_pop_blad = 0.0;
}

void PID::setParametry(double kp, double ti, double td) {
    if (kp < 0.0 || ti < 0.0 || td < 0.0) {
        throw std::invalid_argument("Parametry PID musz¹ byæ nieujemne.");
    }
    m_kp = kp;
    m_ti = ti;
    m_td = td;
}

// ---------------------- WartoscZadana ----------------------
WartoscZadana::WartoscZadana() : m_typsygnalu(skok), m_amplituda(1.0), m_okres(1.0), m_cykl(0.5), m_aktywacja(0), m_czas(0) {}

void WartoscZadana::ustawskok(double amplituda, int aktywacja) {
    m_typsygnalu = skok;
    m_amplituda = amplituda;
    m_aktywacja = aktywacja;
}

void WartoscZadana::ustawsinusoide(double amplituda, double okres) {
    if (amplituda < 0.0 || okres <= 0.0) {
        throw std::invalid_argument("Amplituda musi byæ nieujemna, a okres wiêkszy od 0.");
    }
    m_typsygnalu = sinusoida;
    m_amplituda = amplituda;
    m_okres = okres;
}

void WartoscZadana::ustawprostokatny(double amplituda, double okres, double cykl) {
    if (amplituda < 0.0 || okres <= 0.0 || cykl < 0.0 || cykl > 1.0) {
        throw std::invalid_argument("Amplituda musi byæ nieujemna, okres wiêkszy od 0, a cykl w przedziale [0, 1].");
    }
    m_typsygnalu = prostokatny;
    m_amplituda = amplituda;
    m_okres = okres;
    m_cykl = cykl;
}

double WartoscZadana::generuj() {

    double wartosc = 0.0;
    switch (m_typsygnalu) {
    case skok:
        if (m_czas >= m_aktywacja) wartosc = m_amplituda;
        break;
    case sinusoida:
        wartosc = m_amplituda * sin(2 * 3.14 * (m_czas % static_cast<int>(m_okres)) / m_okres);
        break;
    case prostokatny:
        if ((m_czas % static_cast<int>(m_okres)) < (m_cykl * m_okres)) {
            wartosc = m_amplituda;
        }
        break;
    }
    m_czas++;
    return wartosc;
}

void WartoscZadana::reset() {
    m_czas = 0;
}

// ---------------------- Symulacja ----------------------
Symulacja::Symulacja(std::unique_ptr<ARX> arx, std::unique_ptr<PID> pid, std::unique_ptr<WartoscZadana> wartoscZadana)
    : m_ARX(std::move(arx)), m_PID(std::move(pid)), m_WartoscZadana(std::move(wartoscZadana)), m_zadane(0.0), m_zmierzone(0.0) {}

void Symulacja::setARX(std::unique_ptr<ARX> arx) {
    m_ARX = std::move(arx);
}

void Symulacja::setPID(std::unique_ptr<PID> pid) {
    m_PID = std::move(pid);
}

void Symulacja::setWartoscZadana(std::unique_ptr<WartoscZadana> wartoscZadana) {
    m_WartoscZadana = std::move(wartoscZadana);
}

void Symulacja::setZadane(double zadane) {
    m_zadane = zadane;
}

double Symulacja::krok() {
    if (!m_WartoscZadana || !m_PID || !m_ARX) {
        throw std::logic_error("Symulacja nie zosta³a poprawnie zainicjalizowana.");
    }

    m_zadane = m_WartoscZadana->generuj();
    double sygnal = m_PID->oblicz(m_zadane, m_zmierzone);
    m_zmierzone = m_ARX->krok(sygnal);
    return m_zmierzone;
}

void Symulacja::reset() {
    if (m_ARX) m_ARX->reset();
    if (m_PID) m_PID->reset();
    if (m_WartoscZadana) m_WartoscZadana->reset();
    m_zmierzone = 0.0;
}
