# include "mylib.h"

int main()
{
    int max = 1, nd_kiekis = 0, i=0; // studentu kiekis, namu darbu kiekis
    char pas = 0; // Pasirinkimas tarp vidurkio ir medianos
    char uzkl=0; 
    char arGeneruoti = 0; // Pasirinkimas tarp atisitiktinio generavimo

    cout << "Iveskite namu darbu sk. (Turi buti skaitmuo)" << endl;
    while (true) // Tikrina, kad butu tik sveikasis skaicius
    {
        cin >> nd_kiekis;
        if (!cin)
        {
            cout << "(Turi buti skaitmuo) " << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else break;
    }

    do {
        cout << "Jei norite generuoti sarasa atsitiktinai irasykite 1, jei norite patys pildyti, spauskite 2: " << endl;
        cin >> arGeneruoti;
        cin.clear();
        cin.ignore();
    } while (arGeneruoti != '1' && arGeneruoti != '2'); // Tikrina, kad pasirinkimas teisingas
    studentas* grupe;
    
    if(arGeneruoti=='1'){ // Jei pasirenkama 1, kuriama atsitiktinai
        cout << "Iveskite studentu kieki: " << endl; // Nustatomas saraso ilgis
        cin >> max;
        grupe = new studentas[max];
        for (int i = 0; i < max; i++)
            generate(grupe[i], nd_kiekis); // Kreipiamasi į atsitiktinio generavimo funkcija
    
    }
    else if (arGeneruoti == '2') { // Jei pasirenkama 2, kuriama "rankomis"
        
        grupe = new studentas[max];
        do {
            pild(grupe[i], nd_kiekis); // Kreipimasis į pildymo funkcija
            cout << "Irasykite n, kad uzbaigtumete pildyma: " << endl;
            cin >> uzkl; 
            if (uzkl != 'n') {
                resize(grupe, max); // Kreipimasi į masyvo resize funkcija
                i++;
            }
        } while (uzkl != 'n'); // Jei uzkl yra n, baigiasi ciklas ir pasibaigia sąrašas
    }
    else{ grupe = new studentas[max]; } // Kuriamas tuščias masyvas, jei įvyksta klaida

    do {
        cout << "Jei norite matyti vidurki irasykite 1, jei norite matyti mediana irasykite 2: " << endl; cin >> pas;
    } while (pas != '1' && pas != '2'); // Tikrinama, kad pasirinkimas teisingas

    cout << setw(15) << "Vardas" << setw(20) << "Pavarde"; // Atspausdinama vardo ir pavardės antraštės
    if (pas == '1') { cout << setw(15) << "Vidurkis" << endl; } //Jei pasirinkimas Vidurkis atspausdinima Vidurkio antraštė
    else if (pas == '2') { cout << setw(15) << "Mediana" << endl; } //Jei pasirinkimas Mediana atspausdinima Medianos antraštė
    for (int i = 0; i < max; i++) spausd(grupe[i], nd_kiekis, pas); // Kreipiamasis į spausdinimo funkcija
    delete[] grupe; // Atlaisvinama vieta
}

void pild(studentas& temp, int& nd_kiekis) {
    cout << "Iveskite varda ir pavarde: "; cin >> temp.vardas >> temp.pavarde; // Užpildomas vardas ir pavardė
    temp.paz = new int[nd_kiekis];
    int p=0; //Ivedamas pazymys
    cout << "Iveskite paz. " << endl;
    for (int i = 0; i < nd_kiekis; i++)
    {
       do{
           if (cin >> p) break; 
           cin.clear();
           cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
       }while (true && p>=0 && p<=10); // Tikrina ar pažymys yra skaičius ir ar jis tarp 0 ir 10
        temp.paz[i] = p; // Reikšmė įdedama į masyvą
    }
    cout << "Iveskite egzamino paz. ";
    cin >> temp.egz; // Egzamino pažymys įdedamas į masyvą
    cout << "Duomenys irasyti" << endl;
}

void spausd(studentas& temp, int nd_kiekis, char pas) {
    cout << setw(15) << temp.vardas << setw(20) << temp.pavarde;
    //for (int i = 0; i < nd_kiekis; i++) cout << setw(3) << temp.paz[i];
    //cout << setw(5) << temp.egz << endl;
    if (pas == '1') { cout << setw(15)<< std::fixed << setprecision(2) << vidurk(temp, nd_kiekis) << endl; }
    else if (pas == '2') { cout << setw(15)<< std::fixed << setprecision(2) << median(temp, nd_kiekis) << endl; }
    delete[]temp.paz; // Atlaisvinama vieta
}

void generate(studentas& temp, int nd_kiekis) { // Atsitiktinio generavimo funkcija
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937_64 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int>dist(0, 9);
    string Vard[10]{ "Tomas", "Jonas", "Aleksas", "Benas", "Juozas", "Jurgis", "Domas", "Naglis", "Lukas", "Martynas" };
    string Pav[10]{ "Abligaitis", "Baravicius", "Kristinis", "Mencys", "Plienys", "Plieskis", "Skeitaitis", "Skepenis", "Vunderis", "Zabalskis" };
    temp.vardas = Vard[dist(mt)];   // Iš vardų sąrašo atsitiktinai parenkamas vardas
    temp.pavarde = Pav[dist(mt)];   // Iš vardų sąrašo atsitiktinai parenkamas pavardė

    std::uniform_int_distribution<int>dist2(0, 10);
    temp.paz = new int[nd_kiekis];
    for (int i = 0; i < nd_kiekis; i++) temp.paz[i] = dist2(mt);
    temp.egz = dist2(mt);
}

float vidurk(studentas temp, int nd_kiekis) // Vidurkio apskaičiavimo funkcija
{
    float nam_vid = 0, sum = 0;
    for (int i = 0; i < nd_kiekis; i++)
    {
        sum = sum + temp.paz[i];
    }
    nam_vid = sum / nd_kiekis;
    float vid = float(nam_vid * 0.4 + temp.egz * 0.6);
    return vid;
}

float median(studentas temp, int nd_kiekis)
{
    int newsize = nd_kiekis + 1;
    int* arrkopija = new int[newsize]; // Sukuriamas naujas didesnis masyvas
    for (int i = 0; i < nd_kiekis; i++)
        arrkopija[i] = temp.paz[i]; // Nukopijuojami namų darbų pažymiai į nauja masyvą
    arrkopija[nd_kiekis] = temp.egz; // Prie masyvo pridedamas ir egzamino pažymys
    std::sort(arrkopija, arrkopija + newsize); // Rušiuojami nuo mažiausio iki didžiausio
    if (newsize % 2 != 0)
        return (float)arrkopija[newsize / 2]; //Jei masyvo kiekis nelyginis skaičius, padalijama jo dydis iš 2 ir spausdinimas gauto indekso elementas
    return (float)((arrkopija[(newsize - 1) / 2] + arrkopija[newsize / 2]) / 2.0); //Jei masyvo kiekis lyginis skaičius, du viduriniai elementai sudedami ir padalijami iš 2
    delete[] arrkopija; // Atlaisvinama vieta
}
studentas* resize(studentas *&grupe, int& max) {
    int newSize = max + 1; //Sukuriamas naujas dydis
    studentas* temp = new studentas[newSize]; // Sukuriamas naujas didesnis masyvas
    copy(grupe, grupe + max, temp); // Nukopijuojami seno masyvo duomenys į nauja masyvą
    max = newSize;  // Pakeistas dydis
    delete[] grupe; // Atlaisvinama vieta
    grupe = temp; // Pakeistas masyvas
    return grupe; //Grąžinamas masyvas
}