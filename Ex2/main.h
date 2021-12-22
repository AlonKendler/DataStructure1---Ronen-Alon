#include <iostream>
#include "masterHeap.h"
#include "pair.h"

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
bool maxWarapper(bool reset, masterHeap<pair>* master);
bool deleteMaxWarapper(bool reset, masterHeap<pair>* master);
bool minWarapper(bool reset, masterHeap<pair>* master);
bool deleteMinWarapper(bool reset, masterHeap<pair>* master);
bool insertWarapper(bool reset, masterHeap<pair>* master);
bool medianWarapper(bool reset, masterHeap<pair>* master);

