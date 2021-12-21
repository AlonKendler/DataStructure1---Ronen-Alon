#include "heap.h"

template class heap<int>;

template<class T>
TreeNode<T>* heap<T>::Insert(T* data, TreeNode<T>* twin)
{
    TreeNode<T>* finalPos = new TreeNode<T>();
    finalPos->setData(data);

    if(twin)
    {
        twin->setTwin(finalPos);
        finalPos->setTwin(twin);
    }

    if(head==nullptr)
    {
        head=finalPos;
        tail=finalPos;
    }
    else
    {
        if(head==tail)
        {
            head->setLeft(finalPos);
            finalPos = heapifyUp(finalPos);
            if(head->getParent())
            {
                tail=head;
                head=head->getParent();
            }
            else
            {
                tail=finalPos;
            }
        }
        else
        {
            TreeNode<T> *nextParent=getNextFreeParent();
            if(nextParent->getLeft())
            {
                nextParent->setRight(finalPos);
            }
            else
            {
                nextParent->setLeft(finalPos);
            }
            finalPos=heapifyUp(finalPos);
            if(head->getParent())
            {
                head=head->getParent();
            }
            if(finalPos->getLeft())
            {
                tail=nextParent;
            }
            else
            {
                tail=finalPos;
            }
        }
    }

    itemCount++;

    return finalPos;
}

template <typename T>
TreeNode<T>* heap<T>::getNextFreeParent()
{
    TreeNode<T>* curr=tail;
    TreeNode<T>* next=tail->getParent();

    if(next)
    {
        if(next->getLeft()==tail)
        {
            return next;
        }
        else
        {
            while (next && next->getRight()==curr)
            {
                curr=next;
                next=next->getParent();
            }

            if(next)
            {
                curr=next;
                next=next->getRight();
                while(next)
                {
                    curr=next;
                    next=next->getLeft();
                }

                return curr;
            }
            else
            {
                next=curr->getLeft();
                while(next)
                {
                    curr=next;
                    next=next->getLeft();
                }
                return curr;
            }
            
        }
    }
    return curr;
}

template <typename T>
TreeNode<T>* heap<T>::heapifyDown(TreeNode<T>* node)
{
    if(node)
    {
        if(node->getLeft())
        {
            TreeNode<T>* max = node;
            if(compare(*(node->getLeft()->getData()),*(node->getData())))
            {
                max=node->getLeft();
            }
            if(node->getRight() && compare(*(node->getRight()->getData()),*(max->getData())))
            {
                max=node->getRight();
            }

            if(max==node->getLeft())
            {
                TreeNode<T>* left = node->getLeft();
                
                TreeNode<T>* temp=node->getParent();
                if(temp)
                {
                    if(temp->getRight()==node)
                    {
                        temp->setRight(left);
                    }
                    else
                    {
                        temp->setLeft(left);
                    }
                }

                left->setParent(temp);
                temp=left->getRight();
                left->setRight(node->getRight());
                node->setLeft(left->getLeft());
                node->setRight(temp);
                left->setLeft(node);
                return heapifyDown(node);

            }
            else if(max==node->getRight())
            {
                TreeNode<T>* right = node->getRight();
                
                TreeNode<T>* temp=node->getParent();
                if(temp)
                {
                    if(temp->getRight()==node)
                    {
                        temp->setRight(right);
                    }
                    else
                    {
                        temp->setLeft(right);
                    }
                }

                right->setParent(temp);
                temp=right->getLeft();
                right->setLeft(node->getLeft());
                node->setRight(right->getRight());
                node->setLeft(temp);
                right->setRight(node);
                return heapifyDown(node);
            }
            else
            {
                return node;
            }
        }
        return node;
    }
    else
    {
        return nullptr;
    }
}

template <class T>
TreeNode<T>* heap<T>::heapifyUp(TreeNode<T>* node)
{
    if(node)
    {
        if(node->getParent())
        {
            TreeNode<T>* next=node->getParent();
            TreeNode<T>* curr=node;

            while (next && compare(*(curr->getData()), *(next->getData())))
            {
                TreeNode<T> *temp=next->getParent();
                curr->setParent(temp);
                if(temp)
                {
                    if(temp->getLeft()==next)
                    {
                        temp->setLeft(curr);
                    }
                    else
                    {
                        temp->setRight(curr);
                    }
                }
                if(next->getLeft()!=curr)
                {
                    temp=curr->getLeft();
                    curr->setLeft(next->getLeft());
                    next->setLeft(temp);
                    next->setRight(curr->getRight());
                    curr->setRight(next);
                }
                else
                {
                    temp=curr->getRight();
                    curr->setRight(next->getRight());
                    next->setRight(temp);
                    next->setLeft(curr->getLeft());
                    curr->setLeft(next);
                }
                next=curr->getParent();
            }
            return curr;
        }
        return node;
    }
    return nullptr;
}

template <class T>
void heap<T>::print() const
{
    if(itemCount>0)
    {
        head->print();
        cout << '\n';
        head->printInOrder();
        cout << '\n';
    }
}

template <typename T>
const T& heap<T>::Top() const
{
    return *(head->getData());
}

template <typename T>
TreeNode<T>* heap<T>::deleteTop()
{
    TreeNode<T>* top = head;
    TreeNode<T>* prevTail = getPrevTail();
    
    if(prevTail)
    {

        if(prevTail==head)
        {
            head=tail;
            head->setParent(nullptr);
        }
        else
        {

            head=tail;
            tail=prevTail;

            if(head->getParent())
            {
                TreeNode<T>* parent=head->getParent();
                if(parent->getRight()==head)
                {
                    parent->setRight(nullptr);
                }
                else
                {
                    parent->setLeft(nullptr);
                }
            }
            head->setParent(top->getParent());
            head->setLeft(top->getLeft());
            head->setRight(top->getRight());

            heapifyDown(head);

            if(head->getParent())
            {
                while (head->getParent())
                {
                    head=head->getParent();
                }
            }
            if(tail->getLeft())
            {
                if(tail->getRight())
                {
                    tail=tail->getRight();
                }
                else
                {
                    tail=tail->getLeft();
                }
            }
        }
    }
    else
    {
        tail=nullptr;
        head=nullptr;
    }

    if(itemCount>0)
        itemCount--;

    if(top)
        bro->remove(top);

    return top;
}

template <typename T>
void heap<T>::remove(TreeNode<T>* remove)
{
    if(remove && remove->getTwin())
    {
        TreeNode<T>* twin = remove->getTwin();
        TreeNode<T>* newTail=getPrevTail();

        if(tail->getParent())
        {
            TreeNode<T>* parent =nullptr;
            if(twin==tail)
            {
                if(tail->getParent()->getRight()==tail)
                {
                    tail->getParent()->setRight(nullptr);
                }
                else
                {
                    tail->getParent()->setLeft(nullptr);
                }
            }
            else
            {
                if(tail->getParent()->getRight()==tail)
                {
                    tail->getParent()->setRight(nullptr);
                }
                else
                {
                    tail->getParent()->setLeft(nullptr);
                }

                tail->setParent(twin->getParent());
                if(tail->getParent()->getRight()==twin)
                {
                    tail->getParent()->setRight(tail);
                }
                else
                {
                    tail->getParent()->setLeft(tail);
                }
                tail->setLeft(twin->getLeft());
                tail->setRight(twin->getRight());

                parent = tail->getParent();
                tail = heapifyUp(tail);
                if(tail->getParent()==parent)
                {
                    heapifyDown(tail);
                }
                else
                {
                    heapifyDown(parent);
                }
            }
            if(newTail==twin)
            {
                if(!parent->getLeft())
                {
                    tail=parent;
                }
            }
            else
            {
                tail=newTail;
            }
        }
        else
        {
            head=nullptr;
            tail=nullptr;
        }
        
        delete twin;
        itemCount--;

    }
}

template <class T>
TreeNode<T>* heap<T>::getPrevTail()
{
    if(tail)
    {
        if(tail==head)
        {
            return nullptr;
        }
        else
        {
            TreeNode<T>* curr=tail;
            TreeNode<T>* next=tail->getParent();

            while(next && next->getLeft()==curr)
            {
                curr=next;
                next=next->getParent();
            }

            if(next)
            {
                curr=next;
                next=next->getLeft();
                while (next)
                {
                    curr=next;
                    next=next->getRight();
                }

                return curr;
                
            }
            else
            {
                next=curr->getRight();
                while (next)
                {
                    curr=next;
                    next=next->getRight();
                }
                return curr;
            }
        }
    }
    else
    {
        return nullptr;
    }
}

template <class T>
bool heap<T>::compare(const T& t1, const T& t2)
{
    return maxHeap? t1>t2:t2>t1;
}

template <class T>
void heap<T>::setBro(heap<T>* bro)
{
    this->bro=bro;
}

template <typename T>
int heap<T>::getItemCount() const
{
    return itemCount;
}
