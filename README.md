# ISI-darbai
Objektinis programavimas

# Subversija 0.1

1. Turi masyvų ir vektorių versijas.
3. Leidžia vartotujui sukurti studentų sąrašą atsitiktiniu generavimo būdu arba rašymo.
2. Leidžia vartotujui įrašyti studentų vardus, pavardes, namų darbų pažymius ir egzamino pažymį; (Sutaisyta)
3. Galima rašyti neribotą studentų kiekį, taip pat ir namų darbų pažymių kiekį.
4. Atsitiktiniu generavimo būdu reikia nurodyti tik studentų kiekį ir namų darbų pažymių kiekį, tuomet sugeneruojami vardai, pavardės, namų darbų pažymiai ir egzamino pažymys. Pagal juos suskaičiuojami vidurkiai ar medianos.
5. Turi papildomas bibliotekas **mylib.h** (masyvams) ir **mylibv.h** (vektoriams).
6. Abu header failai yra **main.cpp** viduje.
7. Leidžia atspausdinti  vidurkius ar medianas.

# Subversija 0.2

1. Gali nuskaityti tekstinį failą ir iš jo paimti duomenis.
2. Gali rezultatus atspausdinti ne tik terminale, bet ir faile.
3. Rezultatai išrikiuoti pagal vardus.

# Subversija 0.3

1. Naudotos struktūros
2. Funkcijos perkeltos į naują Funkc.cpp
3. Naudotas header file mylibv.h
4. Naudotas išimčių valdymas.

# Subversija 0.4

1. Tekstinių failu generavimas 
2. Rikiavimas pagal vidurkį į dvi grupes
3. Laiko skaičiavimas procesų analizei


Šia visur namų įrašų kiekis = 10

| Įrašų dydis  | Failo kūrimas užtruko  | Nuskaitymo laikas | Sortinimas užtruko | Dalijamo į dvi grupes laikas | Nelaimėlių įrašymo laikas | Kietekų  įrašymo laikas | Testo laikas |
| ------------- | ------------- |------------- | ------------- |------------- | ------------- |------------- |------------- |
| 1000  | 0.0065138 s  | 0.0043225 s  | 0.0003316 s  | 0.001056 s  | 0.001223 s  | 0.0010597 s  | 0.0390061 s | 
| 10000  | 0.0572551 s  | 0.0384501 s | 0.0031802 s  | 0.0071276 s  | 0.0110183 s  | 0.0102847 s  | 0.150651 s  | 
| 100000  | 0.546904 s  | 0.407215 s | 0.03508 s  | 0.0732076 s  | 0.105783 s  | 0.110102 s  | 1.32431 s  | 
| 1000000  | 5.53011 s  | 4.47793 s | 0.362167 s  | 0.826443 s  | 1.1141 s  | 1.07979 s  | 13.7416 s  | 
| 10000000  | 55.5535 s | 79.5637 s | 5.29102 s  | 8.27994 s  | 10.3865 s  | 10.6915 s  | 173.786 s  | 

# Subversija 0.5

1. Skirtingų konteinerių testavimas
2. Vector
3. List 
4. Deque

Testavimas

Tie patys failai
Šia visur namų įrašų kiekis = 5

Naudoto kompiuterio specif:
Cpu: Intel core i5-9300H 2.40GHz
Ram: 8GB
SSD

Vector

| Įrašų dydis  | Nuskaitymo laikas | Sortinimas užtruko | Dalijamo į dvi grupes laikas |
| ------------- | ------------- |------------- | ------------- |
| 1000  | 0.0038537 s  | 0.0018601 s  | 0.0012167 s  |
| 10000  | 0.0299059 s | 0.0171331 s  | 0.0130275 s  | 
| 100000  | 0.287498 s | 0.175003 s  | 0.129624 s  | 
| 1000000  | 2.94094 s | 1.95796 s  | 1.39944 s  | 
| 10000000  | 38.3692 s | 21.1892 s  | 13.7691 s  |


List

| Įrašų dydis  | Nuskaitymo laikas | Sortinimas užtruko | Dalijamo į dvi grupes laikas |
| ------------- | ------------- |------------- | ------------- |
| 1000  | 0.0037964 s  | 0.0059368 s  | 0.0041525 s  |
| 10000  | 0.0385268 s | 0.0886534 s  | 0.05309 s | 
| 100000  | 0.374071 s | 1.20647 s  | 0.659838 s  | 
| 1000000  | 3.80985 s | 15.9973 s  | 8.16042 s  | 
| 10000000  | 62.1358 s | 204.147 s | 144.564 s  |


Deque

| Įrašų dydis  | Nuskaitymo laikas | Sortinimas užtruko | Dalijamo į dvi grupes laikas |
| ------------- | ------------- |------------- | ------------- |
| 1000  | 0.0041432 s  | 0.00075214 s  | 0.0043546 s  |
| 10000  | 0.0376656 s | 0.0699046 s  | 0.049531 s  | 
| 100000  | 0.380264 s | 0.765129 s  | 0.497214 s  | 
| 1000000  | 3.81546 s | 8.17611 s  | 5.07492 s  | 
| 10000000  | 91.7171 s | 89.4753 s  | 84.9982 s  |


# Subversija 1.0

Instrukcija:
1. Atsiūsti release
2. Pasirinkti norimo konteinerio folderį
3. Paleisti RUNME.bat
4. Pasirinkti tarp 4 pasirinkimų (1 - savarankiško duomenų įvedimo, 2 - atsitiktinio generavimo, 3- duomenų nuskaitymo iš failo, 4 - failų generavimo iš esamo failo ar naujai sukurto)
5. Pasirinkus 1, reikia pačiam įvesti studento duomenis (vardą, pavardę, pažymius), taip pat pasirinkimas tarp išvedimo tarp pažymių medianos ir vidurkio
6. Pasirinkus 2 reikia įvesti kiek studentu generuos ir kiek maksimalus namų darbų pažymių skaičius
7. Pasirinkus 3 reikia įvesti tekstinio failo pavadinamą, kuris turi būti tam pačiame folderį, kur RUNME.bat
8. Pasirinkus 4 reikia pasirinkti strategija failo dalijimo tarp Nelaimėlių ir Kietekų.
9. Rezultatams išvedus galime tęsti programą.

Dalijimo strategijos:

1 - Dalijimas vieno konteinerio į naujus du to pačio tipo konteinerius
2 - Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "Nelaimėliai". 


Vector

Po algoritmų copy_if ir remove_if panaudojimo

Strategija 1

| Įrašų dydis  | Dalijamo į dvi grupes laikas |
| ------------- | ------------- |
| 1000  |  0.0002181 s |
| 10000  |  0.0016884 s | 
| 100000  | 0.0161331 s  | 
| 1000000  |  0.141169 s  | 
| 10000000  |  11.0912 s  |

Strategija 2

| Įrašų dydis  | Dalijamo į dvi grupes laikas |
| ------------- | ------------- |
| 1000  |  0.0001639 s  |
| 10000  |  0.0038112 s  | 
| 100000  | 0.0138368 s | 
| 1000000  |  0.208622 s  | 
| 10000000  |  3.98532 s  |


List

Strategija 1

| Įrašų dydis  | Dalijamo į dvi grupes laikas |
| ------------- | ------------- |
| 1000  | 0.0005991 s |
| 10000  | 0.0075418 s | 
| 100000  | 0.0726583 s  | 
| 1000000  |  0.765922 s  | 
| 10000000  | 69.766 s  |

Strategija 2

| Įrašų dydis  | Dalijamo į dvi grupes laikas |
| ------------- | ------------- |
| 1000  |  0.0005524 s  |
| 10000  |  0.0052371 s | 
| 100000  | 0.089833 s  | 
| 1000000  |  1.01964 s  | 
| 10000000  |  57.4779 s  |

Deque

Strategija 1

| Įrašų dydis  | Dalijamo į dvi grupes laikas |
| ------------- | ------------- |
| 1000  | 0.0006008 s  |
| 10000  |  0.0061158 s  | 
| 100000  | 0.0657753 s  | 
| 1000000  | 0.78586 s | 
| 10000000  | 47.7059 s |

Strategija 2

| Įrašų dydis  | Dalijamo į dvi grupes laikas |
| ------------- | ------------- |
| 1000  |  0.0003884 s  |
| 10000  |  0.0042577 s  | 
| 100000  | 0.0594054 s  | 
| 1000000  |  0.663879 s  | 
| 10000000  |  18.4896 s  |


