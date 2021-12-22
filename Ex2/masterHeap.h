#include "heap.h"
#include <stdexcept>

template <typename T>
class masterHeap
{
private:
     heap<T>* highMaxHeap;
     heap<T>* highMinHeap;
     int highItemCount;
     heap<T>* lowMaxHeap;
     heap<T>* lowMinHeap;
     int lowItemCount;

    void rebalance();

public:
    masterHeap(): highMaxHeap(nullptr), highMinHeap(nullptr), highItemCount(0) ,lowMaxHeap(nullptr), lowMinHeap(nullptr), lowItemCount(0){}
    ~masterHeap();
    void CreateEmpty();
    const T& max();
    const T& deleteMax();
    const T& min();
    const T& deleteMin();
    const T& median();
    void insert(T& val);
    int getItemCount();
    
};