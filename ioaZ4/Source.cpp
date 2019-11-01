#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

const double PI = 3.14159265359;

//Funkcija za izracunavanje aproksimativne nule:
double aproksimativnaNula(int i, int n) {
	return cos(PI*(i - 0.25) / (n + 0.5));
}


//Lezanrov polinom 10. stepena - HARDCODE !
double lezanr10(double x) {
	return ((46189 * pow(x, 10)- 109395 * pow(x, 8) + 90090 * pow(x, 6) - 30030 * pow(x, 4) + 3465 * pow(x, 2) - 63) / 256);
}

//Izvod Lezanrovog polinoma 10. stepena - HARDCODE !
double lezanr10izvod(double x) {
	return ((46189 * 10 * pow(x, 9) - 109395 * 8 * pow(x, 7) + 90090 * 6 * pow(x, 5) - 30030 * 4 * pow(x, 3) + 3465 * 2 * x) / 256);
}


//Main program:
int main(){
	
	double nule[5];
	double xk, xkPrethodno;

	//Petlja za pronalazak 5 nula po Njutnu:
	for (int i = 1; i <= 5; i++) {
		xkPrethodno = aproksimativnaNula(i, 10);
		xk = xkPrethodno - (lezanr10(xkPrethodno) / lezanr10izvod(xkPrethodno));

		while ((abs((xk-xkPrethodno))/abs(xk)) >= pow(10,-15)) {
			xkPrethodno = xk;
			xk = xkPrethodno - (lezanr10(xkPrethodno) / lezanr10izvod(xk));
		}

		nule[i - 1] = xk;
	}

	//Setovanje preciznosti ispisa i sam ispis:
	cout << std::setprecision(15);
	cout << "Nule Lezanrovog polinoma su:" << endl;
	int j = 1;
	for (int i = 4; i >= 0; i--) {
		cout << i+1 << ".: ";
		cout <<"(-" << nule[i] <<") " << "i" << " (" << nule[i]<<")" << endl;
		
	}

	system("pause");
	return 0;
}
