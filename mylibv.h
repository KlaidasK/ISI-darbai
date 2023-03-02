#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <random>
#include <chrono>
#include <iterator>
#include <sstream>


using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::setprecision;
using std::string;
using std::copy;
using std::numeric_limits;
using std::vector;
using std::istringstream;
using std::istringstream;

char pas, pas2, pas3; // Pasirinkimas tarp pazymiu ivedimo ir atsitiktinio generavimo, pasirinkimas tarp vidurkio ir medianos
std::ofstream out_f("Studentai.txt");

template <class T>
void statistika(vector <T> &tempas) {
	cout << "Vektoriaus size: " << tempas.size() << endl;
	cout << "Vektoriaus capacity: " << tempas.capacity() << endl;
}

struct studentas {
	string vardas, pavarde = "", randoms="";
    vector<int> paz;
    int egz=0;
    float vid=0;
    float med=0;
    bool operator() (studentas i, studentas j) { return (i.vardas < j.vardas); }
} student;

void pild(studentas &temp, int &max);
void spausd(studentas &temp);
float vidurk(studentas temp);
float median(studentas temp);
void generate(studentas& temp, int nd_kiekis);
void skaitymas(std::string read_vardas, vector <studentas>& grupe, int &max);
