#include <stdio.h>
#include <iostream>
#include <complex>
#include <math.h>

using namespace std;

const double pi = 3.14;
const double e = 2.71828;

complex<double> funFs(int n, double beta, double teta, double delta, double d) {
	double fi = delta + beta * d * cos(teta);
	complex<double> f;
	f.real(0.0);
	f.imag(0.0);
	complex<double> j;
	j.real(0);
	j.imag(1);
	for (double k = 0; k < n; k++)
		f += pow(e, -1.0 * j * k * fi);

	return f;
}

void main() {
	int n = 5;

	complex<double> fs;
	double re, im;
	double beta = 20.0 * pi;
	double teta = pi / 4.0;
	double d = 1 / 20.0;
	
	double moduo = 0;

	FILE* out;
	fopen_s(&out, "Zadatak.txt", "w");
	for (double i = 0; i < 2 * pi; i += pi / 50) {

		fs = funFs(n, beta, teta, i, d);
		moduo = abs(fs);
		fprintf(out, "%f\n", moduo);

	}

	fclose(out);
	system("pause");
}