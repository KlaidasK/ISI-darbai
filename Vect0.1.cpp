# include "mylibv.h"

int main()
{
	char uzkl;
	int stud_kiek = 0;
	vector<studentas> grupe;
	studentas laikinas;
	do {
		cout << "Norint paciam ivesti studento pazymius spauskite 1, jei norit generuoti duomenis atsitiktinai spauskite 2 :" << endl; cin >> pas;

	} while (pas != '1' && pas != '2');
	if (pas == '1') {
		do {
			cout << "Iveskite studento duomenis: \n";
			laikinas.paz.reserve(max);

			pild(laikinas);
			grupe.push_back(laikinas);
			laikinas.paz.clear();
			cout << "Pabaigai spauskite n, kitaip veskite kito studento duomenis po bet kokio klaviso nuspaudimo" << endl;
			cin >> uzkl;
		} while (uzkl != 'n' && uzkl != 'N');
	}
	else if (pas == '2') {
		
		cout << "Iveskite studentu skaiciu: " << endl; cin >> stud_kiek;
		cout << "Iveskite namu pazymiu skaiciu: " << endl; cin >> max;
		for (int i = 0; i < stud_kiek; i++)
		{
			laikinas.paz.reserve(stud_kiek);
			generate(laikinas, max);
			grupe.push_back(laikinas);
			laikinas.paz.clear();
		}
	}
	do {
		cout << "Pasirinkite 1 jei norite matyti vidurki, jei norite matyti mediana paspauskite 2 : " << endl;
		cin >> pas2;
	} while (pas2 != '1' && pas2 != '2');

	cout << setw(15) << "Vardas" << setw(20) << "Pavarde";
	if (pas2 == '1') { cout << setw(23) << "Gal. Vidurkis" << endl; }
	else if (pas2 == '2') { cout << setw(23) << "Gal. Mediana" << endl; };
	cout << "------------------------------------------------------------" << endl;
	for (auto& i : grupe) spausd(i);
	grupe.clear();
}

void pild(studentas& temp)
{
	int p = 0;
	cout << "Iveskite varda ir pavarde: "; cin >> temp.vardas >> temp.pavarde;

	cout << "Iveskite pazymius beige rasyti iveskite, bet koki simboli" << endl;

	do {
		cin >> p;
		if (!cin) break;
		if (pas == '1') { temp.paz.push_back(p); }
		max++;
		temp.paz.resize(max);
	} while (cin);
	max = 0;
	cin.clear();
	std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	do {
		cout << "Iveskite egzamino paz. (Turi buti skaitmuo)" << endl;
		if (cin >> temp.egz) break;
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	} while (true);
	cout << "Duomenys irasyti" << endl;
}

void spausd(studentas& temp)
{
	temp.vid = vidurk(temp);
	temp.med = median(temp);
	cout << setw(15) << temp.vardas << setw(20) << temp.pavarde;
	if (pas2 == '1') { cout << setw(15) << std::fixed << setprecision(2) << temp.vid << endl; }
	else if (pas2 == '2') { cout << setw(15) << std::fixed << setprecision(2) << temp.med << endl; }
}

float vidurk(studentas temp)
{
	float nam_vid = 0, sum = 0;
	for (const auto& i : temp.paz) { sum = sum + i; }
	if (temp.paz.size() == 0) temp.paz.resize(1);
	nam_vid = sum / temp.paz.size(); // pakeisti did, jei reikia
	float vid = float(nam_vid * 0.4 + temp.egz * 0.6);
	return vid;
}

float median(studentas temp)
{
	vector<int> vectkopija;
	typedef vector<int>::size_type vec_sz;
	for (int i = 0; i < temp.paz.size(); i++)
		vectkopija.push_back(temp.paz[i]);
	vectkopija.push_back(temp.egz);
	vec_sz size = vectkopija.size();
	sort(vectkopija.begin(), vectkopija.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? float(vectkopija[mid] + vectkopija[mid - 1]) / 2 : vectkopija[mid];
}



void generate(studentas& temp, int nd_kiekis) { // Atsitiktinio generavimo funkcija
	using hrClock = std::chrono::high_resolution_clock;
	std::mt19937_64 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int>dist(0, 9);

	string Vard[10]{ "Tomas", "Jonas", "Aleksas", "Benas", "Juozas", "Jurgis", "Domas", "Naglis", "Lukas", "Martynas" };
	string Pav[10]{ "Abligaitis", "Baravicius", "Kristinis", "Mencys", "Plienys", "Plieskis", "Skeitaitis", "Skepenis", "Vunderis", "Zabalskis" };
		std::uniform_int_distribution<int>dist2(0, 10);
		temp.vardas = Vard[dist(mt)];   // Iš vardų sąrašo atsitiktinai parenkamas vardas
		temp.pavarde = Pav[dist(mt)];	// Iš vardų sąrašo atsitiktinai parenkamas pavardė
		
		temp.paz.resize(max);
		temp.paz.push_back(dist2(mt));
		temp.egz = dist2(mt);
}