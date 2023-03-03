# include "mylibv.h"

void skaitymas(std::string read_vardas, vector <studentas>& grupe, int& max) {
	std::vector<std::string> splited;
	std::string eil, line;
	double sk = 0.0; // Iš viso žodžių faile
	int stul = 0; //stulpelių sk.
	std::ifstream open_f2(read_vardas);
	if(!open_f2.is_open()) throw ("Failas tuscias arba neegzistuoja aplanke:");
	studentas temp;

	while (open_f2) {
		if (!open_f2.eof()) {
			getline(open_f2, line);
			max++; // Eilučių skaičius, taip pat ir studentų skaičius
		}
		else break;
	}
	open_f2.close();

	std::ifstream open_f(read_vardas);
	while (open_f) {
		if (!open_f.eof()) {
			open_f >> eil;
			splited.push_back(eil);
			sk++; // Žodžių sk.
		}
		else break;
	}
	open_f.close();

	stul =float( sk / max); // Susiskaičiuojama stulpelių skaičius, stulpeliai visada sveikas skaičius, nes kievienoje eilutėje turi būti tiek pat duomenų
	


	temp.paz.reserve(max - 1); // Pirmoji eilutė neskaičiuojama, nes ji tik antraštė

	for (int i = stul; i < sk; i = i + stul) {
		temp.vardas = splited[i];
		temp.pavarde = splited[i + 1];
		for (int j = i + 2; j < i + stul - 1; j++) temp.paz.push_back(stoi(splited[j]));
		temp.egz = stoi(splited[i + stul - 1]);
		grupe.push_back(temp);
		temp.paz.clear();
	}
	splited.resize(0);
}

void spausd(studentas& temp, char pas2, char pas3, std::ofstream &out_f) // Rezultatų atspausdinimas
{
	temp.vid = vidurk(temp); // Kreipimasis į vidurkio funkcija 
	temp.med = median(temp); // Kreipimasis į medianos funkcija


	if (pas3 == 'n') { // Jei norima spausdinti į terminalą
		cout << left << setw(20) << temp.vardas;
		cout << left << setw(25) << temp.pavarde;
		if (pas2 == '1') { cout << left << setw(30) << std::fixed << setprecision(2) << temp.vid << endl; }
		else if (pas2 == '2') { cout << left << setw(30) << std::fixed << setprecision(2) << temp.med << endl; }
		else if (pas2 == '3') { cout << left << setw(30) << std::fixed << setprecision(2) << temp.vid << setw(35) << std::fixed << setprecision(2) << temp.med << endl; }
	}
	else if (pas3 == 'y') { //Jei norima spausdinti į failą
		out_f << left << setw(20) << temp.vardas;
		out_f << left << setw(25) << temp.pavarde;
		if (pas2 == '1') { out_f << left << setw(30) << std::fixed << setprecision(2) << temp.vid << endl; }
		else if (pas2 == '2') { out_f << left << setw(30) << std::fixed << setprecision(2) << temp.med << endl; }
		else if (pas2 == '3') { out_f << left << setw(30) << std::fixed << setprecision(2) << temp.vid << left << setw(35) << std::fixed << setprecision(2) << temp.med << endl; }
	}
}

void generate(studentas& temp, int nd_kiekis) { // Atsitiktinio generavimo funkcija
	using hrClock = std::chrono::high_resolution_clock;
	std::mt19937_64 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int>dist(0, 9); // Vardam ir pavardėm
	string Vard[10]{ "Tomas", "Jonas", "Aleksas", "Benas", "Juozas", "Jurgis", "Domas", "Naglis", "Lukas", "Martynas" };
	string Pav[10]{ "Abligaitis", "Baravicius", "Kristinis", "Mencys", "Plienys", "Plieskis", "Skeitaitis", "Skepenis", "Vunderis", "Zabalskis" };

	std::uniform_int_distribution<int>dist2(0, 10); // Pažymiams
	temp.vardas = Vard[dist(mt)];   // Iš vardų sąrašo atsitiktinai parenkamas vardas
	temp.pavarde = Pav[dist(mt)];	// Iš vardų sąrašo atsitiktinai parenkamas pavardė
	for (int i = 0; i < nd_kiekis; i++)	temp.paz.push_back(dist2(mt)); // Generuojami pažymiai
	temp.egz = dist2(mt); // Generuojami egzamino pažymys
}

void pild(studentas& temp, int& max) // Duomenų įvedimo funkcija
{
	int p = 0; // Laikinas pažymio kintamasis
	cout << "Iveskite varda ir pavarde: "; cin >> temp.vardas >> temp.pavarde;

	cout << "Iveskite pazymius beige rasyti iveskite, bet koki simboli" << endl;

	do {
		cin >> p;
		if (!cin) break;
		temp.paz.push_back(p); // Vedami nd pažymiai
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
	} while (true); // Vedamas egzamino pažymys
	cout << "Duomenys irasyti" << endl;
}

float vidurk(studentas temp) // Vidurkio skaičiavimas
{
	float nam_vid = 0, sum = 0;
	for (const auto& i : temp.paz) { sum = sum + i; }
	if (temp.paz.size() == 0) temp.paz.resize(1);
	nam_vid = sum / temp.paz.size();
	float vid = float(nam_vid * 0.4 + temp.egz * 0.6);
	return vid;
}

float median(studentas temp) //Medianos skaičiavimas
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






