#include <iostream>
#include <deque>
#include <array>
#include <random>
#include <cmath>
#include "klasy.h"
/*
TODO:
ARX:



PID:




*/
using namespace std;


int main()
{
	deque<int> yi = { 1,2,3,4 };
	cout << yi[2] << endl;

	vector<double> A = { -0.4 };
	vector<double> B = { 0.6 };
	int delay = 1;
	double zaklocenia = 0.01;
	auto arx = make_unique<ARX>(A, B, delay, zaklocenia);
	double kp = 1.0;
	double ti = 0.5;
	double td = 0.1;
	auto pid = make_unique<PID>(kp, ti, td);
	Symulacja symulacja(move(arx), move(pid));

	WartoscZadana sygnal;
	sygnal.ustawskok(1.0, 10);

	const int krokisymulacji = 50;
	const double aktualizacja = 10;

	cout << "czas		zadane		wyjscie" << endl;

	for (int i = 0; i < krokisymulacji; i++)
	{
		double setpoint = sygnal.generuj();
		symulacja.setZadane(setpoint);
		double wyjscie = symulacja.krok();

		cout << i << "		" << setpoint << "		" << wyjscie << endl;
	}
	return 0;
}
