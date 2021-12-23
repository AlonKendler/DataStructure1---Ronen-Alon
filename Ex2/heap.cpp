#include "heap.h"

template class heap<pair>;


template <typename T> heap<T>::heap(int maxCapacity): maxHeap(true), arr(nullptr) , itemCount(0), bro(nullptr), maxCapacity(maxCapacity) 
{
    arr = new heapItem<T>[maxCapacity];
}

template <typename T> heap<T>::heap(bool max, int maxCapacity): maxHeap(max), arr(nullptr) , itemCount(0), bro(nullptr) , maxCapacity(maxCapacity)
{
    arr = new heapItem<T>[maxCapacity];
}

template <typename T> heap<T>::heap(heap<T>* bro, int maxCapacity): maxHeap(true), arr(nullptr) , itemCount(0), bro(bro) , maxCapacity(maxCapacity)
{
    arr = new heapItem<T>[maxCapacity];
}

template <typename T> heap<T>::heap(bool max, heap<T>* bro, int maxCapacity): maxHeap(max), arr(nullptr) , itemCount(0), bro(bro) , maxCapacity(maxCapacity)
{
    arr = new heapItem<T>[maxCapacity];
}

template <typename T> heap<T>::~heap()
{
    if(arr)
    {
        delete [] arr;
    }
}

template<class T> int heap<T>::Insert(const T* data, int twin)
{
    if(itemCount<maxCapacity)
    {
        arr[itemCount].setData(data);

        if(twin!=-1)
        {
            bro->setTwin(twin,itemCount);
            arr[itemCount].setTwin(twin);
        }

        itemCount++;

        return heapifyUp(itemCount-1);
    }
    return -1;
}

template <typename T> void heap<T>::setTwin(int node, int twinIndex)
{
    arr[node].setTwin(twinIndex);
}

template <typename T> int heap<T>::heapifyDown(int node)
{
    if(node>=0 && node<itemCount)
    {
        int leftInd=2*node+1;
        int rightInd=2*node+2;
        bool replaced = true;
        while(itemCount>leftInd && replaced)
        {
            replaced = false;
            int maxInd = node;
            if(compare(arr[leftInd].getData(), arr[node].getData())) 
            // left child > node
            {
                maxInd=leftInd;
            }
            if(rightInd<itemCount && compare(arr[rightInd].getData(),arr[maxInd].getData())) 
            // right child > max(left child, index)
            {
                maxInd=rightInd;
            }

            if(maxInd!=node)
            {
                replaced = true;
                
                heapItem<T> temp=arr[node];
                arr[node] = arr[maxInd];
                arr[maxInd] = temp;
                
                
                if(arr[node].getTwin()!=-1)
                {
                    bro->setTwin(arr[node].getTwin(), node);
                }
                if(arr[maxInd].getTwin()!=-1)
                {
                    bro->setTwin(arr[maxInd].getTwin(), maxInd);
                }
                
                node = maxInd;
                leftInd = 2*node+1;
                rightInd = 2*node+2;
                
            }
        }
        return node;
    }
    return -1;
}

template <class T> int heap<T>::heapifyUp(int node)
{
    if(node!=-1)
    {
        if(node>0)
        {
            heapItem<T> temp;
            int parent = (node-1)/2;
            bool replace=compare(arr[node].getData(), arr[parent].getData());
            while(parent>=0 && replace)
            {
                temp=arr[parent];
                arr[parent]=arr[node];
                arr[node]=temp;

                if(arr[node].getTwin()!=-1)
                {
                    bro->setTwin(arr[node].getTwin(),node);
                }
                if(arr[parent].getTwin()!=-1)
                {
                    bro->setTwin(arr[parent].getTwin(), parent);
                }

                node=parent;
                if(node!=0)
                {
                    parent=(node-1)/2;
                }
                else
                {
                    parent=-1;
                }
            }

            return node;
        }
        return 0;
    }
    return -1;
}

template <typename T>
const T* heap<T>::Top() const
{
    return arr->getData();
}

template <typename T> const T* heap<T>::deleteTop()
{
    if(itemCount<maxCapacity && itemCount>0)
    {
        const T* top = arr[0].getData();
        int twin = arr[0].getTwin();
        
        
        if(itemCount==1)
        {
            itemCount--;
        }
        else if(itemCount>1)
        {
            itemCount--;
            arr[0] = arr[itemCount];
            bro->setTwin(arr[0].getTwin(), 0);
            int final = heapifyDown(0);
            bro->setTwin(arr[final].getTwin(), final);
        }
        
        arr[itemCount].setData(nullptr);
        arr[itemCount].setTwin(-1);

        if(twin!=-1)
            bro->remove(twin);

        return top;
    } 
    return nullptr;
}

template <typename T> void heap<T>::remove(int remove)
{
    if(remove>=0&&remove<itemCount)
    {
        if(remove==itemCount-1)
        {
            itemCount--;
            arr[itemCount].setData(nullptr);
            arr[itemCount].setTwin(-1);
        }
        else
        {
            itemCount--;
            arr[remove]=arr[itemCount];
            bro->setTwin(arr[remove].getTwin(), remove);
            heapifyDown(remove);
            heapifyUp(remove);
            arr[itemCount].setData(nullptr);
            arr[itemCount].setTwin(-1);
        }
    }
}

template <class T>
bool heap<T>::compare(const T* t1, const T* t2)
{
    return maxHeap? *t1>*t2:*t2>*t1;
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
