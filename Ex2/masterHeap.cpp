#include "masterHeap.h"

template class masterHeap<pair>;

template <typename T> void masterHeap<T>::CreateEmpty(int maxSize)
{
    int highCapacity=0, lowCapacity=0;
    if(maxSize%2==0)
    {
        highCapacity=maxSize/2+1;
        lowCapacity=maxSize/2;
    }
    else
    {
        highCapacity=maxSize/2+1;
        lowCapacity=maxSize/2;
    }

    highMaxHeap = new heap<T>(nullptr,highCapacity);
    highMinHeap = new heap<T>(false, highMaxHeap,highCapacity);
    highMaxHeap->setBro(highMinHeap);

    lowMaxHeap = new heap<T>(nullptr,lowCapacity);
    lowMinHeap = new heap<T>(false, lowMaxHeap,lowCapacity);
    lowMaxHeap->setBro(lowMinHeap);

    highItemCount=lowItemCount=0;
}

template <typename T> masterHeap<T>::~masterHeap()
{

    while(getItemCount()>0)
    {
        const T* val = deleteMax();
        delete val;
    }

    if(lowMaxHeap)
    {
        delete lowMaxHeap;
    }

    if(lowMinHeap)
    {
        delete lowMinHeap;
    }
    
    if(highMaxHeap)
    {
        delete highMaxHeap;
    }

    if(highMinHeap)
    {
        delete highMinHeap;
    }

}

template <typename T> const T* masterHeap<T>::max()
{
    if(highItemCount!=0)
    {
        return highMaxHeap->Top();
    }
    return nullptr;
}

template <typename T> const T* masterHeap<T>::deleteMax()
{
    if(highItemCount!=0)
    {
        const T* data = highMaxHeap->deleteTop();
        highItemCount--;
        rebalance();
        return data;
    }
    return nullptr;
}

template <typename T> const T* masterHeap<T>::min()
{
    if(highItemCount!=0)
    {
        if(lowItemCount==0)
        {
            return highMinHeap->Top();
        }
        else
        {
            return lowMinHeap->Top();
        }
    }
    return nullptr;
}

template <typename T> const T* masterHeap<T>::deleteMin()
{
    if(highItemCount!=0)
    {
        const T* removed = nullptr;
        if(lowItemCount==0)
        {
            removed = highMinHeap->deleteTop();
            highItemCount--;
        }
        else
        {
            removed = lowMinHeap->deleteTop();
            lowItemCount--;
        }
        rebalance();
        return removed;
    }

    return nullptr;
}

template <typename T> const T* masterHeap<T>::median()
{
    if(highItemCount!=0)
    {
        if(lowItemCount==highItemCount)
        {
            return lowMaxHeap->Top();
        }
        else
        {
            return highMinHeap->Top();
        }

    }

    return nullptr;
}

template <typename T> void masterHeap<T>::insert(T& val)
{
    int inserted= highMaxHeap->Insert(&val, -1);
    highMinHeap->Insert(&val, inserted);

    highItemCount++;
    rebalance();    
}

template <typename T> void masterHeap<T>::rebalance()
{
    if(highItemCount==lowItemCount+1)
    {
        if(lowItemCount!=0)
        {
            const T* minHigh = highMinHeap->Top();
            const T* maxLow = lowMaxHeap->Top();
            if(*maxLow > *minHigh)
            {
                const T* min = highMinHeap->deleteTop();
                const T* max = lowMaxHeap->deleteTop();

                int inserted = highMaxHeap->Insert(max, -1);
                highMinHeap->Insert(max, inserted);

                inserted = lowMinHeap->Insert(min, -1);
                lowMaxHeap->Insert(min, inserted);
            }
        }
    }
    else if(highItemCount==lowItemCount)
    {
        
    }
    else if(highItemCount+1==lowItemCount)
    {
        const T* max = lowMaxHeap->deleteTop();
        int inserted = highMinHeap->Insert(max, -1);
        highMaxHeap->Insert(max, inserted);
        highItemCount++;
        lowItemCount--;
    }
    else
    {
        const T* min = highMinHeap->deleteTop();
        int inserted = lowMinHeap->Insert(min, -1);
        lowMaxHeap->Insert(min, inserted);
        highItemCount--;
        lowItemCount++;
    }
}

template <typename T> int masterHeap<T>::getItemCount()
{
    return lowItemCount+highItemCount;
}
