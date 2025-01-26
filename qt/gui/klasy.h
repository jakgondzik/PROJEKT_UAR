#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <array>
#include <random>
#include <memory>
#include <cmath>
#include <stdexcept>

class ARX {
protected:
    std::deque<double> m_yi;
    std::vector<double> m_vec_a, m_vec_b;
    int m_delay;
    double m_zaklocenia;
    std::deque<double> m_ui;
    std::default_random_engine generator;
    std::normal_distribution<double> gzaklocen;

public:
    ARX(const std::vector<double>& vec_a, const std::vector<double>& vec_b, int delay, double zaklocenia = 0.0);
    double krok(double u);
    void setVektory(const std::vector<double>& vec_a, const std::vector<double>& vec_b);
    void setDelay(int delay);
    void setZaklocenia(double zaklocenia);
    void reset();
    std::pair<std::vector<double>, std::vector<double>> getVektory() const { return {m_vec_a, m_vec_b}; }
    int getDelay() const { return m_delay; }
    double getZaklocenia() const { return m_zaklocenia; }
};

class PID {
protected:
    double m_kp, m_ti, m_td, m_suma, m_pop_blad;

public:
    PID(double p, double i, double d);
    double obliczP(double cel, double zmierzone);
    double obliczI();
    double obliczD(double cel, double zmierzone);
    double oblicz();
    void reset();
    void setParametry(double kp, double ti, double td);
    double getKp() const { return m_kp; }
    double getTi() const { return m_ti; }
    double getTd() const { return m_td; }
};


enum TypSygnalu { skok, sinusoida, prostokatny };

class WartoscZadana {
protected:
    TypSygnalu m_typsygnalu;
    double m_amplituda, m_okres, m_cykl;
    int m_aktywacja, m_czas;

public:
    WartoscZadana();
    void ustawskok(double amplituda, int aktywacja);
    void ustawsinusoide(double amplituda, double okres);
    void ustawprostokatny(double amplituda, double okres, double cykl);
    double generuj();
    void reset();
};

class Symulacja {
protected:
    std::unique_ptr<ARX> m_ARX;
    std::unique_ptr<PID> m_PID;
    std::unique_ptr<WartoscZadana> m_WartoscZadana;
    double m_zadane, m_zmierzone;

public:
    Symulacja(std::unique_ptr<ARX> arx, std::unique_ptr<PID> pid, std::unique_ptr<WartoscZadana> wartoscZadana);
    void setARX(std::unique_ptr<ARX> arx);
    void setPID(std::unique_ptr<PID> pid);
    void setWartoscZadana(std::unique_ptr<WartoscZadana> wartoscZadana);

    void setZadane(double zadane);
    double krok();
    void reset();
    ARX* getARX() const { return m_ARX.get(); }  // Zwraca wskaünik do ARX
    PID* getPID() const { return m_PID.get(); }  // Zwraca wskaünik do PID
    WartoscZadana* getWartoscZadana() const { return m_WartoscZadana.get(); }
};
