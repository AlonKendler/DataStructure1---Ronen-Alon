#include "subSumVersions.h"

#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using std::ios_base;
using std::ofstream;
using std::fixed;
using std::setprecision;
using std::string;

vector<subSumPair>* funcTimer(vector<subSumPair>* (*func)(int*, int, int),const char* func_name, int arr[], int size, int x);
