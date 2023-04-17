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
using std::cerr;
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
using std::runtime_error;


template <class T>
void statistika(vector <T> &tempas) {
	cout << "Vektoriaus size: " << tempas.size() << endl;
	cout << "Vektoriaus capacity: " << tempas.capacity() << endl;
}

const struct studentas {
	string vardas, pavarde = "";
    vector<int> paz;
    int egz=0;
    float vid=0, med=0;
    bool operator() (studentas i, studentas j) { return (i.vid < j.vid); }
} student;

void pild( studentas& temp,  int& max);
void spausd( studentas& temp,  char pas2,  char pas3, std:: ofstream& out);
void generate( studentas& temp, int nd_kiekis, int i);
float vidurk( studentas temp);
float median( studentas temp);
void skaitymas( string read_vardas,  vector <studentas>& grupe, int& max);
void failai(studentas& temp, int nd_kiekis, std::ofstream& out_f);
void isrinkimas(vector<studentas> grupe, vector<studentas>& temp, vector<studentas>& temp2, char strat);