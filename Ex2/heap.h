#include "treeNode.h"
#include <iostream>

using std::ostream;

/* template<class T> class heap;
template<class T> ostream& operator<<(ostream& cout, heap<T>* h);
 */
template<class T>
class heap
{
private:
    TreeNode<T>* head;
    TreeNode<T>* tail;
    int itemCount;

    TreeNode<T>* getNextFreeParent();
    TreeNode<T>* heapifyUp(TreeNode<T>* node);

public:
    heap(): head(nullptr), tail(nullptr) , itemCount(0) {}

    const TreeNode<T>* Insert(T data);
    const T& Top() const;
    void fixHeap(TreeNode<T>* borked);
    TreeNode<T>* removeTop();

    template<class U>
    friend ostream& operator<<(ostream& cout, heap<U>* h);
};