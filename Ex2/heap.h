#include <iostream>
#include "heapItem.h"

using std::ostream;

/* template<class T> class heap;
template<class T> ostream& operator<<(ostream& cout, heap<T>* h);
 */
template<class T>
class heap
{
private:
    bool maxHeap;
    heapItem<T>* arr;
    int itemCount;
    heap<T>* bro;
    int maxCapacity;

    int heapifyDown(int node);
    int heapifyUp(int node);
    bool compare(const T* t1, const T* t2);
    void remove(int remove);

public:
    heap(int maxCapacity);
    heap(bool max, int maxCapacity);
    heap(heap<T>* bro, int maxCapacity);
    heap(bool  max, heap<T>* bro, int maxCapacity);
    ~heap();

    int Insert(const T* data, int twin);
    const T* Top() const;
    const T* deleteTop();
    void setBro(heap<T>* bro);
    int getItemCount() const;
    void setTwin(int node, int twinIndex);
};