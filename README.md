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
