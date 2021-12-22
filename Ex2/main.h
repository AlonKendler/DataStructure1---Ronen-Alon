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
bool maxWarapper(bool reset, masterHeap<int>* master);
bool deleteMaxWarapper(bool reset, masterHeap<int>* master);
bool minWarapper(bool reset, masterHeap<int>* master);
bool deleteMinWarapper(bool reset, masterHeap<int>* master);
bool insertWarapper(bool reset, masterHeap<int>* master);
bool medianWarapper(bool reset, masterHeap<int>* master);

