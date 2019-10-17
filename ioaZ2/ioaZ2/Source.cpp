#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;



void bruteForce() {
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;
	long long int brojac = 0;
	FILE * f;
	fopen_s(&f, "bruteForce.txt", "w");

	
	//V2: Svaka cena pocinje od prethodnog + provera uslova - cca 3.5 milijarde iteracija:
	//Ostavio sam ove 2 "optimizacije" posto se u suprotnom kod jako dugo izvrsava.
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
	fclose(f);
}

void optimizacija() {
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;
	long int brojac = 0;
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
	fprintf(f, "%ld\n", brojac);
	fclose(f);
}


//Petlja mi se ponavlja 2x sto je maksimalno 1400 ponavljanja, sto ne bi trebalo da oduzme puno vremena
void faktorizacija() {
	long int brojac = 0;
	int brojacFaktora = 0;
	int * faktori;
	FILE * f;
	fopen_s(&f, "faktorizacija.txt", "w");

	for (int i = 1; i <= 711; i++) {
		brojac++;
		if ((711*100*100*100) % i == 0)
			brojacFaktora++;
	}

	faktori = new int[brojacFaktora];

	int j = 0;

	for (int i = 1; i <= 711; i++) {
		brojac++;
		if ((711 * 100 * 100 * 100) % i == 0) {
			faktori[j++] = i;
		}
	}

	for (int i = 0; i < brojacFaktora - 3; i++) {
		for (int j = i + 1; j < brojacFaktora - 2; j++) {
			for (int k = j + 1; k < brojacFaktora - 1; k++) {
				for (int l = k + 1; l < brojacFaktora; l++) {
					brojac++;
					if ((faktori[i] + faktori[j] + faktori[k] + faktori[l] == 711) &&
						(faktori[i] * faktori[j] * faktori[k] * faktori[l] == 711*100*100*100)) {
						double cena1 = faktori[i] / 100.0;
						double cena2 = faktori[j] / 100.0;
						double cena3 = faktori[k] / 100.0;
						double cena4 = faktori[l] / 100.0;
						fprintf(f, "%.2f, %.2f, %.2f, %.2f\n", cena1, cena2, cena3, cena4);
					}
				}

			}
		}
	}
	fprintf(f, "%ld\n", brojac);
	fclose(f);
}

int main() {

	//A) Imamo 4 proizvoda ciji je zbir 7.11, a isti im je i proizvod:
	bruteForce();

	//B) Cena jednog preko ostala 3:
	optimizacija();

	//V) Faktorizacija proizvoda na proste umnoske:
	faktorizacija();

	//G) Koji je najbrzi, a koji najlakse napisati?
	cout << "Najbrzi je FAKTORIZACIJA, a najlaksi za pisanje: BRUTEFORCE" << endl;
	system("pause");
	return 0;
}