# include "mylibv.h"


int main()
{
	char uzkl;
	int stud_kiek = 0, max = 0;
	char pas, pas2, pas3; // Pasirinkimas tarp pazymiu ivedimo ir atsitiktinio generavimo, pasirinkimas tarp vidurkio ir medianos
	std::ofstream out_f("Rezultatai.txt");
	vector<studentas> grupe;
	studentas laikinas;
	do {
		cout << "Norint paciam ivesti studento pazymius spauskite 1, jei norit generuoti duomenis atsitiktinai spauskite 2, o  jei norite duomenis paimti is failo spauskite 3 :" << endl; cin >> pas;

	} while (pas != '1' && pas != '2' && pas != '3');
	if (pas == '1') { // Įvedami duomenys
		do {
			cout << "Iveskite studento duomenis: \n";
			laikinas.paz.reserve(max);
			pild(laikinas, max);
			grupe.push_back(laikinas);
			laikinas.paz.clear();
			cout << "Pabaigai spauskite n, kitaip veskite kito studento duomenis po bet kokio klaviso nuspaudimo" << endl;
			cin >> uzkl;
		} while (uzkl != 'n' && uzkl != 'N');
	}
	else if (pas == '2') { // Generuojami duomenys

		cout << "Iveskite studentu skaiciu: " << endl; cin >> stud_kiek;
		try {
			if (stud_kiek == 0) throw("Klaida. Sarasas tuscias!");
		}
		catch (const char* msg) {
			cerr << msg << endl;
			return EXIT_FAILURE;
		}
		cout << "Iveskite namu pazymiu skaiciu: " << endl; cin >> max;
		
		for (int i = 0; i < stud_kiek; i++)
		{
			laikinas.paz.reserve(stud_kiek);
			generate(laikinas, max);
			grupe.push_back(laikinas);
			laikinas.paz.clear();
		}
	}
	else if (pas == '3') { // Duomenys paimami iš failo
		try {
			skaitymas("Kursiokai.txt", grupe, max); // Kreipimasis į skaitymo funkcija
		}
		catch (const char* msg) {
			cerr << msg << endl;
			return EXIT_FAILURE;
		}

		
};

	do {
		cout << "Pasirinkite 1 jei norite matyti vidurki, jei norite matyti mediana paspauskite 2, o jei norite matyti abu spauskite 3 : " << endl;
		cin >> pas2;
	} while (pas2 != '1' && pas2 != '2' && pas2 != '3'); // Pasirinkimas tarp vidurkio ar medianos, arba abiejų






	do {
		cout << "Ar norite isvesti rezultatus i faila (y/n) : " << endl;
		cin >> pas3;
	} while (pas3 != 'y' && pas3 != 'n'); // Pasirinkimas tarp išvedimo

	std::sort(grupe.begin(), grupe.end(), student); // Rikiavimas pagal vardą

	if (pas3 == 'n') { // Spausdinama į terminalą
		cout << left << setw(20) << "Vardas" << left << setw(25) << "Pavarde";
		if (pas2 == '1') { cout << setw(30) << "Gal. Vidurkis" << endl; }
		else if (pas2 == '2') { cout << setw(30) << "Gal. Mediana" << endl; }
		else if (pas2 == '3') { cout << setw(30) << "Gal. Vidurkis" << setw(35) << "Gal. Mediana" << endl; };
		cout << "--------------------------------------------------------------------------------------------" << endl;
		for (auto& i : grupe) spausd(i,pas2,pas3, out_f);
	}
	else if (pas3 == 'y') { // Spausdinama į failą
		out_f << left << setw(20) << "Vardas" << left << setw(25) << "Pavarde";
		if (pas2 == '1') { out_f << setw(30) << "Gal. Vidurkis" << endl; }
		else if (pas2 == '2') { out_f << setw(30) << "Gal. Mediana" << endl; }
		else if (pas2 == '3') { out_f << setw(30) << "Gal. Vidurkis" << setw(35) << "Gal. Mediana" << endl; };
		out_f << "-------------------------------------------------------------------------------------------" << endl;
		for (auto& i : grupe) spausd(i,pas2,pas3, out_f);
	};
	grupe.clear();
}
