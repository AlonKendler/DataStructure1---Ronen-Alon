#include "heap.h"

template<class T>
const TreeNode<T>* heap<T>::Insert(T data)
{
    TreeNode<T>* final = new TreeNode<T>(data);
    TreeNode<T> *parent = getNextFreeParent();
    if(parent->getLeft()==nullptr)
    {
        parent->setLeft(final);
    }
    else
    {
        parent->setRight(final);
    }
    tail = heapifyUp(final);

    return final;
}

template<class T>
TreeNode<T>* heap<T>::heapifyUp(TreeNode<T>* t)
{
    
    return nullptr;
}

template<class T>
TreeNode<T>* heap<T>::getNextFreeParent()
{
    TreeNode<T>* prev = tail;
    TreeNode<T>* next = tail->getParent();
    while(next!=nullptr && next->getRight()==prev)
    {
        prev=next;
        next = next->getParent();
    }
    if(next==nullptr)
    {
        prev = next->getLeft();
        while (prev)
        {
            next = prev;
            prev = prev->getLeft();
        }
        return next;
    }
    else
    {
        prev=next;
        next=next->getRight();
        while (next)
        {
            prev=next;
            next=next->getLeft();
        }
        
        return next;
    }
}

template<class T>
const T& heap<T>::Top() const
{
    return head->getData();
}

template<class T>
void heap<T>::fixHeap(TreeNode<T> *borked)
{
    
}

template<class T>
TreeNode<T>* heap<T>::removeTop()
{
    TreeNode<T>* top = head;
    
    if(tail && tail!=top)
    {
        TreeNode<T>* tail_parent = tail->getParent();
        if(tail_parent)
        {
            if(tail_parent->getLeft()==tail)
            {
                tail_parent->setLeft(nullptr);
            }
            else
            {
                tail_parent->setRight(nullptr);
            }
        }

        tail->setParent(nullptr);

        tail->setLeft(head->getLeft());
        tail->setRight(head->getRight());

        head=tail;

        fixHeap(head);
    }
    return top;
}

template<class U>
ostream& operator<<(ostream& cout, heap<U>* h)
{
    return cout << h->head;
}
