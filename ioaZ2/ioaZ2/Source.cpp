#include <iostream>

using namespace std;



void bruteForce() {
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;
	long long int brojac = 0;
	FILE * f;
	fopen_s(&f, "bruteForce.txt", "w");

	
	//V2: Svaka cena pocinje od prethodnog + provera uslova - brze 10x:
	for (c1 = 1; c1 < 711; c1++) {
		for (c2 = c1; c2 < 711; c2++) {
			if ((c1 + c2 <= 711) && (c1 * c2 <= 711*100)) {
				for (c3 = c2; c3 < 711; c3++) {
					if ((c1 + c2 + c3 <= 711) && (c1 * c2 * c3 <= 711 * 100 * 100)) {
						for (c4 = c3; c4 < 711; c4++) {
							brojac++;
							if ((c1 + c2 + c3 + c4 == 711) && (c1 * c2 * c3 * c4 == 711 * 100 * 100 * 100)) {
								double cena1 = c1 / 100.0;
								double cena2 = c2 / 100.0;
								double cena3 = c3 / 100.0;
								double cena4 = c4 / 100.0;
								fprintf(f, "%.2f, %.2f, %.2f, %.2f\n", cena1, cena2, cena3, cena4);
							}
						}
					}
				}
			}
		}
	}
	fprintf(f, "%lld\n", brojac);
	system("pause");
}

void optimizacija() {
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;
	long long int brojac = 0;
	FILE * f;
	fopen_s(&f, "optimizacija.txt", "w");

	for (c1 = 1; c1 < 711; c1++) {
		for (c2 = c1; c2 < 711; c2++) {
			if ((c1 + c2 <= 711) && (c1 * c2 <= 711 * 100)) {
				for (c3 = c2; c3 < 711; c3++) {
					if ((c1 + c2 + c3 <= 711) && (c1 * c2 * c3 <= 711 * 100 * 100)) {
						brojac++;
						c4 = 711 - c1 - c2 - c3;
						if ((c1 + c2 + c3 + c4 == 711) && (c1 * c2 * c3 * c4 == 711 * 100 * 100 * 100)) {
							double cena1 = c1 / 100.0;
							double cena2 = c2 / 100.0;
							double cena3 = c3 / 100.0;
							double cena4 = c4 / 100.0;
							fprintf(f, "%.2f, %.2f, %.2f, %.2f\n", cena1, cena2, cena3, cena4);
						}
					}
				}
			}
		}
	}
	fprintf(f, "%lld\n", brojac);
}

int main() {

	//A) Imamo 4 proizvoda ciji je zbir 7.11, a isti im je i proizvod:
	//bruteForce();

	//B) Cena jednog preko ostala 3:
	//optimizacija();

	//V) Faktorizacija proizvoda na proste umnoske:
	//faktorizacija();

	//G) Koji je najbrzi, a koji najlakse napisati?
	cout << "Najbrzi je , a najlaksi za pisanje: BRUTEFORCE" << endl;
	return 0;
}