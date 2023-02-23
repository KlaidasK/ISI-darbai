#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>
#include <vector>
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

int max = 0, did=0; // namu pazymiu max dydis
char pas; // Pasirinkimas tarp pazymiu ivedimo ir atsitiktinio generavimo
char pas2; // Pasirinkimas tarp vidurkio ir medianos

template <class T>
void statistika(vector <T> &tempas) {
	cout << "Vektoriaus size: " << tempas.size() << endl;
	cout << "Vektoriaus capacity: " << tempas.capacity() << endl;
}

struct studentas {
	string vardas="", pavarde = "";
    vector<int> paz;
    int egz=0;
    float vid=0;
    float med=0;
};

void pild(studentas &temp);
void spausd(studentas &temp);
float vidurk(studentas temp);
float median(studentas temp);
