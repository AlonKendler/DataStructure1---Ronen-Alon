#include "heap.h"

template <typename T>
class masterHeap
{
private:
     heap<T>* highMaxHeap;// two heaps max and min containing the same values
     heap<T>* highMinHeap;// all values here will have higher priority then low heaps
     int highItemCount;
     heap<T>* lowMaxHeap;
     heap<T>* lowMinHeap;
     int lowItemCount;

    void rebalance();

public:
    masterHeap(): highMaxHeap(nullptr), highMinHeap(nullptr), highItemCount(0) ,lowMaxHeap(nullptr), lowMinHeap(nullptr), lowItemCount(0){}
    ~masterHeap();
    void CreateEmpty(int maxSize);
    const T* max();
    const T* deleteMax();
    const T* min();
    const T* deleteMin();
    const T* median();
    void insert(T& val);
    int getItemCount();
    
};