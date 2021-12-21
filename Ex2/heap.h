#include <iostream>
#include "treeNode.h"

using std::ostream;

/* template<class T> class heap;
template<class T> ostream& operator<<(ostream& cout, heap<T>* h);
 */
template<class T>
class heap
{
private:
    bool maxHeap;
    TreeNode<T>* head;
    TreeNode<T>* tail;
    int itemCount;
    heap<T>* bro;

    TreeNode<T>* getNextFreeParent();
    TreeNode<T>* heapifyDown(TreeNode<T>* node);
    TreeNode<T>* heapifyUp(TreeNode<T>* node);
    TreeNode<T>* getPrevTail();
    bool compare(const T& t1, const T& t2);
    void remove(TreeNode<T>* remove);
public:
    heap(): maxHeap(true) ,head(nullptr), tail(nullptr) , itemCount(0), bro(nullptr) {}
    heap(bool max): maxHeap(max), head(nullptr), tail(nullptr) , itemCount(0), bro(nullptr) {}
    heap(heap<T>* bro): maxHeap(true) ,head(nullptr), tail(nullptr) , itemCount(0), bro(bro) {}
    heap(bool max, heap<T>* bro): maxHeap(max), head(nullptr), tail(nullptr) , itemCount(0), bro(bro) {}


    TreeNode<T>* Insert(T* data, TreeNode<T>* twin);
    const T& Top() const;
    void print() const;
    TreeNode<T>* deleteTop();
    void setBro(heap<T>* bro);
    int getItemCount() const;
};