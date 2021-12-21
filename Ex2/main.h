#include <iostream>
#include "masterHeap.h"

using std::cin;
using std::cout;

enum class Action
{
    aMax,
    bDeleteMax,
    cMin,
    dDeleteMin,
    eCreateEmpty,
    fInsert,
    gMedian,
    notValid
};

Action getAction();