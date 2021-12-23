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

/**
 * @brief inserts the value to last place and fixes heap up
 * 
 * @tparam T - the type of the master heap need to have an > operator to work
 * @param data - the data pointer
 * @param twin - the twin to connect to from the other heap
 * @return int - returns final position it was inserted to connect to twin
 */
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

/**
 * @brief fix the index given down the heap
 * 
 * @tparam T - the type of the master heap need to have an > operator to work
 * @param node 
 * @return int - returns the last index of the value in the heap (after fixing)
 */
template <typename T> int heap<T>::heapifyDown(int node)
{
    if(node>=0 && node<itemCount)
    {
        int leftInd=2*node+1;
        int rightInd=2*node+2;
        bool replaced = true;
        while(itemCount>leftInd && replaced)
        {
            replaced = false;// flag to see if we replaced down the heap
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
                replaced = true;// mark that we need to continue the loop
                
                heapItem<T> temp=arr[node];// replace with the bigger child
                arr[node] = arr[maxInd];
                arr[maxInd] = temp;
                
                // fix the twin indexes
                if(arr[node].getTwin()!=-1)
                {
                    bro->setTwin(arr[node].getTwin(), node);
                }
                if(arr[maxInd].getTwin()!=-1)
                {
                    bro->setTwin(arr[maxInd].getTwin(), maxInd);
                }
                
                // move to new fix point
                node = maxInd;
                leftInd = 2*node+1;
                rightInd = 2*node+2;
            }
        }
        return node;
    }
    return -1;
}

/**
 * @brief fix the index given up the heap
 * 
 * @tparam T - the type of the master heap need to have an > operator to work
 * @param node 
 * @return int - returns the last index of the value in the heap (after fixing)
 */
template <class T> int heap<T>::heapifyUp(int node)
{
    if(node!=-1)
    {
        if(node>0)
        {
            heapItem<T> temp;
            int parent = (node-1)/2;
            bool replace=compare(arr[node].getData(), arr[parent].getData()); // check if node > parent
            while(parent>=0 && replace)
            {
                temp=arr[parent]; // replace them
                arr[parent]=arr[node];
                arr[node]=temp;

                // fix twins
                if(arr[node].getTwin()!=-1)
                {
                    bro->setTwin(arr[node].getTwin(),node);
                }
                if(arr[parent].getTwin()!=-1)
                {
                    bro->setTwin(arr[parent].getTwin(), parent);
                }

                // move up to new parent after replacment
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

/**
 * @brief removes the top of the heap by replacing with the last value and fixing down
 * 
 * @tparam T - the type of the master heap need to have an > operator to work
 * @return const T* the removed value's pointer (needs to be freed by caller!)
 */
template <typename T> const T* heap<T>::deleteTop()
{
    if(itemCount<maxCapacity && itemCount>0)
    {
        const T* top = arr[0].getData();
        int twin = arr[0].getTwin();
        
        
        if(itemCount==1) // no need to replace with last value
        {
            itemCount--;
        }
        else if(itemCount>1)
        {
            itemCount--;
            arr[0] = arr[itemCount];// replaces with the last value
            bro->setTwin(arr[0].getTwin(), 0);// fixes twin indexes
            int final = heapifyDown(0);//fix down and get the last location it reached
            bro->setTwin(arr[final].getTwin(), final);// fix twins again in the new location
        }
        
        // delete junk at end
        arr[itemCount].setData(nullptr);
        arr[itemCount].setTwin(-1);

        // remove the twin from other heap
        if(twin!=-1)
            bro->remove(twin);

        return top;
    } 
    return nullptr;
}

/**
 * @brief this function assums the rest of the heap is correct before the remove
 * it replaces with the tail and then fixes up and down as neccessary
 * @tparam T - the type of the master heap need to have an > operator to work
 * @param remove - the index to remove
 */
template <typename T> void heap<T>::remove(int remove)
{
    if(remove>=0&&remove<itemCount)
    {
        if(remove==itemCount-1)// removing the last value is a special case
        {
            itemCount--;
            arr[itemCount].setData(nullptr);
            arr[itemCount].setTwin(-1);
        }
        else
        {
            itemCount--;
            arr[remove]=arr[itemCount]; // replace the removed with the last value
            bro->setTwin(arr[remove].getTwin(), remove);// fix twin values according to change
            heapifyDown(remove);// fix the heap down
            heapifyUp(remove);// fix heap up
            arr[itemCount].setData(nullptr);//delete the junk left at the end
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
