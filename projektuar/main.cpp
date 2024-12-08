#include "klasy.h"
#include <iostream>
#include <vector>
#include <memory>
/*
TODO:
ARX:



PID:




*/

int main()
{
    try
    {
        // Ustawienia modelu ARX
        std::vector<double> A = { -0.4 }; // Wspó³czynniki A
        std::vector<double> B = { 0.6 };  // Wspó³czynniki B
        int delay = 1;
        int iteracje = 50;
        double zaklocenia = 0.01;

        auto arx = std::make_unique<ARX>(A, B, delay, iteracje, zaklocenia);

        // Ustawienia regulatora PID
        double kp = 0.2;
        double ti = 7.0;
        double td = 0.1;

        auto pid = std::make_unique<PID>(kp, ti, td);

        // Symulacja
        Symulacja symulacja(std::move(arx), std::move(pid));

        // Generator wartoœci zadanej
        WartoscZadana sygnal;
        sygnal.ustawskok(1.0, 10); // Skok jednostkowy aktywowany w kroku 10

        const int krokisymulacji = 50;

        std::cout << "Czas\tZadane\tWyjscie" << std::endl;

        for (int i = 0; i < krokisymulacji; ++i)
        {
            double setpoint = sygnal.generuj();
            symulacja.setZadane(setpoint);
            double wyjscie = symulacja.krok();

            std::cout << i << "\t" << setpoint << "\t" << wyjscie << std::endl;
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Wyst¹pi³ b³¹d: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}