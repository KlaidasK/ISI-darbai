#pragma once
#include <iostream>
#include <iomanip>
#include<array> 
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

struct studentas {
	string vardas="", pavarde = "";
	int* paz = nullptr;
    int egz=0;
};

void pild(studentas &temp, int &n);
void spausd(studentas& temp, int nd_kiekis, char pas);
float vidurk(studentas temp, int nd_kiekis);
float median(studentas temp, int nd_kiekis);
void generate(studentas& temp, int nd_kiekis);
studentas* resize(studentas *&grupe, int& max);