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
    bool maxHeap;// if this is true then its a max heap - otherwise its aminimum heap
    heapItem<T>* arr;// the static item array of the heap
    int itemCount;
    heap<T>* bro;// the other heap (if this heap is a minimum then bro is maximum)
    int maxCapacity;

    int heapifyDown(int node);// fixes down while assuming the rest is correct except this value
    int heapifyUp(int node);// fixes up while assuming the rest is correct except this heap
    bool compare(const T* t1, const T* t2);// returns true if t1>t2
    void remove(int remove);// removes from middle of the heap while fixing it

public:
    heap(int maxCapacity);
    heap(bool max, int maxCapacity);
    heap(heap<T>* bro, int maxCapacity);
    heap(bool  max, heap<T>* bro, int maxCapacity);
    ~heap();

    int Insert(const T* data, int twin);// inserts the data pointer while attaching it to the twin in the other heap
    const T* Top() const;// returns a connected pointer to the heap. should not be freed!!
    const T* deleteTop();// deletes the top of the heap and returns the disconnected pointer 
    void setBro(heap<T>* bro);
    int getItemCount() const;
    void setTwin(int node, int twinIndex); // set the twin of the pointer in index 'node'
};