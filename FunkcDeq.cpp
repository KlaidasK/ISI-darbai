# include "mylibd.h"

void pild(studentas& temp, int& max) // Duomen? ?vedimo funkcija
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
		if (cin>>temp.egz) break;
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	} while (true); // Vedamas egzamino pažymys
	cout << "Duomenys irasyti" << endl;
}

void generate(studentas& temp, int nd_kiekis, int i) { // Atsitiktinio generavimo funkcija
	using hrClock = std::chrono::high_resolution_clock;
	std::mt19937_64 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	const int size = 10;
	temp.vardas = "Vardas" + std::to_string(i + 1);
	temp.pavarde = "Pavarde" + std::to_string(i + 1);
	std::uniform_int_distribution<int>dist2(0, 10); // Pažymiams
	//temp.paz.reserve(nd_kiekis);
	for (int j = 0; j < nd_kiekis; j++)
	{
		temp.paz.push_back(dist2(mt));
	}// Generuojami pažymiai
	temp.egz = dist2(mt); // Generuojami egzamino pažymys
}

void skaitymas(std::string read_vardas, std::deque<studentas>& grupe, int& max) {
	std::deque<string> splited;
	std::string word, line;
	max = 0;
	double sk = 0.0; // Iš viso žodži? faile
	int stul = 0; //stulpeli? sk.
	std::ifstream open_f(read_vardas);
	if (!open_f.is_open()) throw ("Failas neegzistuoja aplanke:");
	studentas temp;
	auto start2 = std::chrono::high_resolution_clock::now(); auto st2 = start2;
	while (getline(open_f, line)) {

		// count line
		++max;

		std::stringstream ss(line);

		// extract all words from line
		while (ss >> word) {
			splited.push_back(word);
			// count word
			++sk;
		}
	}
	open_f.close();
	
	stul = float(sk / max); // Susiskai?iuojama stulpeli? skai?ius, stulpeliai visada sveikas skai?ius, nes kievienoje eilut?je turi b?ti tiek pat duomen?
	
	for (int i = 0; i < stul; i++) { //Pašalinama antraštė
		splited.pop_front();
	}
	sk = sk - stul;
	--max;

	//cout << "stulpeliai: " << stul << endl;
	//cout << "eilutes: " << max << endl;
	//cout << "zodziai: " << sk << endl;



	for (int i = 0; i < sk; i = i + stul) {
		temp.vardas = splited[i];
		temp.pavarde = splited[i + 1];
		for (int j = i + 2; j < i + stul - 1; j++) temp.paz.push_back(stoi(splited[j]));
		temp.egz = stoi(splited[i + stul - 1]);
		temp.vid = vidurk(temp);
		grupe.push_back(temp);
		temp.paz.clear();
	}

	splited.resize(0);
	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff2 = end2 - start2; // Skirtumas (s)
	std::cout << "Failo is " << max << " iraso nuskaitymo laikas: " << diff2.count() << " s\n";
}

void spausd(studentas& temp, char pas2, char pas3, std::ofstream& out_f) // Rezultat? atspausdinimas
{
	temp.vid = vidurk(temp); // Kreipimasis ? vidurkio funkcija 
	temp.med = median(temp); // Kreipimasis ? medianos funkcija


	if (pas3 == 'n') { // Jei norima spausdinti ? terminal?
		cout << left << setw(20) << temp.vardas;
		cout << left << setw(25) << temp.pavarde;
		if (pas2 == '1') { cout << left << setw(30) << std::fixed << setprecision(2) << temp.vid << endl; }
		else if (pas2 == '2') { cout << left << setw(30) << std::fixed << setprecision(2) << temp.med << endl; }
		else if (pas2 == '3') { cout << left << setw(30) << std::fixed << setprecision(2) << temp.vid << setw(35) << std::fixed << setprecision(2) << temp.med << endl; }
	}
	else if (pas3 == 'y') { //Jei norima spausdinti ? fail?
		out_f << setw(20) << left << temp.vardas;
		out_f << setw(25) << left << temp.pavarde;
		if (pas2 == '1') { out_f << std::fixed << setprecision(2) << setw(30) << left << temp.vid << '\n'; }
		else if (pas2 == '2') { out_f << setw(30) << std::fixed << setprecision(2) << left << temp.med << endl; }
		else if (pas2 == '3') { out_f << setw(30) << std::fixed << setprecision(2) << left << temp.vid << setw(30) << std::fixed << setprecision(2) << left << temp.med << endl; }
	}
}

float vidurk(studentas temp) // Vidurkio skai?iavimas
{
	float nam_vid = 0, sum = 0;
	for (const auto& i : temp.paz) { sum = sum + i; }
	if (temp.paz.size() == 0) temp.paz.resize(1);
	nam_vid = sum / temp.paz.size();
	float vid = float(nam_vid * 0.4 + temp.egz * 0.6);
	return vid;
}

float median(studentas temp) //Medianos skai?iavimas
{
	std::deque<int> dequekopija;
	typedef list<int>::size_type list_sz;
	for (int i = 0; i < temp.paz.size(); i++)
	{
		dequekopija.push_back(temp.paz[i]);
		
	}
	dequekopija.push_back(temp.egz);
	list_sz size = dequekopija.size();
	sort(dequekopija.begin(), dequekopija.end());
	list_sz mid = size / 2;
	auto itr = dequekopija.begin();
	if (dequekopija.size() % 2 == 0) {
		for (int i = 0; i < mid; i++) {
			itr++;
		}
		return((float)*itr + *--itr) / 2;
	}
	// n is odd
	else {
		for (int i = 0; i < mid; i++) {
			itr++;
		}
		return(float)*itr;
	}
}

void failai(studentas& temp, int nd_kiekis, std::ofstream& out_f) { // Atspausdinimi studentų failai be rezultatų
	out_f << setw(20) << left << temp.vardas;
	out_f << setw(25) << left << temp.pavarde;
	for (auto i : temp.paz) {
		out_f << setw(5) << i << setw(5);
	}
	out_f << temp.egz << "\n";
}

void isrinkimas(std::deque<studentas> grupe, std::deque<studentas> &Nel, std::deque<studentas> &Kiet) {
	auto start3 = std::chrono::high_resolution_clock::now(); auto st3 = start3; //Pradedamas dalijimas ? dvi grupes
	for (auto& i : grupe)
	{	
		if (vidurk(i) < 5.0) {			//Nelaimeliai išskirstomi

			Nel.push_back(i);
		}
		else if (vidurk(i) >= 5.0) {		//Kietekai išskirstomi

			Kiet.push_back(i);
		}
	}
	
	sort(Nel.begin(), Nel.end(), student);
	sort(Kiet.begin(), Kiet.end(), student);

	auto end3 = std::chrono::high_resolution_clock::now();						// Baigiamas dalijimas ? dvi grupes
	std::chrono::duration<double> diff3 = end3 - start3;						// Skirtumas (s)
	std::cout << grupe.size() << " iraso dalijamo i dvi grupes laikas: " << diff3.count() << " s\n";
}




