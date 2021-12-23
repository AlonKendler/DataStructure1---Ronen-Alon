#include <iostream>
#include "pair.h"

using std::ostream;
using std::cout;

template<typename T>
class heapItem 
{
private:
    T* data;
    int twinIndex;
public:
    heapItem(): twinIndex(-1) {}
    heapItem(int twinIndex): twinIndex(twinIndex) {}
    
    int getTwin();
    T* getData() const;


    void setData(const T* data);
    void setTwin(int twinIndex);

    bool operator!=(const heapItem<T> &cmp) const;
};