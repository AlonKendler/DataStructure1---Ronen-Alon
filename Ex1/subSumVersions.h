#pragma once
#include <vector>
#include "itemStack.h"

using std::vector;

struct subSumPair
{
    subSumPair(int num1, int num2): num1(num1), num2(num2){} 
    int num1;
    int num2;
};

vector<subSumPair>* subSumIterrative(int arr[], int size, int x);
vector<subSumPair>* subSumRecursiveWrap(int arr[], int size, int x);
vector<subSumPair>* subSumRecursiveEmulated(int arr[], int size, int x);