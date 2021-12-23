#include "masterHeap.h"

template class masterHeap<pair>;

/**
 * @brief 
 * 
 * @tparam T - the type of the master heap need to have an > operator to work
 * @param maxSize -the expected maximum size of the structure
 */
template <typename T> void masterHeap<T>::CreateEmpty(int maxSize)
{
    int highCapacity=0, lowCapacity=0;
    if(maxSize%2==0)
    {
        // since all numbers go trough the high heaps we need one more in those heaps
        highCapacity=maxSize/2+1;
        lowCapacity=maxSize/2;
    }
    else
    {
        highCapacity=maxSize/2+1;
        lowCapacity=maxSize/2;
    }

    // we allocate both heap pairs and connect them to each other
    highMaxHeap = new heap<T>(nullptr,highCapacity);
    highMinHeap = new heap<T>(false, highMaxHeap,highCapacity);
    highMaxHeap->setBro(highMinHeap);

    lowMaxHeap = new heap<T>(nullptr,lowCapacity);
    lowMinHeap = new heap<T>(false, lowMaxHeap,lowCapacity);
    lowMaxHeap->setBro(lowMinHeap);

    highItemCount=lowItemCount=0;
}

/**
 * @brief Destroy the master Heap<T>::master Heap object
 * this makes sure to empty the structure and delete all value pointers
 * before deleting the heaps themselves
 * 
 * @tparam T - the type of the master heap need to have an > operator to work
 */
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

/**
 * @brief if there is a maximum it will return it
 * 
 * @tparam T - the type of the master heap need to have an > operator to work
 * @return const T* - nullptr if no max is found (empty) otherwise it returns the max's pointer
 */
template <typename T> const T* masterHeap<T>::max()
{
    // no need to check the low heaps, 
    // because we always make sure one of two happens:
    // 1. there is one more in the high heaps
    // 2. there is an equal amount of values in both
    if(highItemCount!=0)
    {
        return highMaxHeap->Top();
    }
    return nullptr;
}

/**
 * @brief deletes the max value from the structure
 * makes sure to rebalance the structure so high part 
 * has one more or equal amount of values.
 * returns a pointer to be freed by caller
 * 
 * @tparam T - the type of the master heap need to have an > operator to work
 * @return const T* - the removed pointer from the structure (needs to be freed by caller)
 */
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

/**
 * @brief if there is a minimum it will return it
 * 
 * @tparam T - the type of the master heap need to have an > operator to work
 * @return const T* - nullptr if no min is found (empty) otherwise it returns the min's pointer
 */
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

/**
 * @brief deletes the min value from the structure
 * makes sure to rebalance the structure so high part 
 * has one more or equal amount of values.
 * returns a pointer to be freed by caller
 * 
 * @tparam T - the type of the master heap need to have an > operator to work
 * @return const T* - the removed pointer from the structure (needs to be freed by caller)
 */
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

/**
 * @brief if there is a median it will return it
 * 
 * @tparam T - the type of the master heap need to have an > operator to work
 * @return const T* - nullptr if no median is found (empty) otherwise it returns the median's pointer
 */
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

/**
 * @brief inserts the value's ptr to the structure while keeping the balance in the structure
 * 
 * @tparam T - the type of the master heap need to have an > operator to work
 * @param val -  the value to insert to the structure. needs to allocate a T type value and pass a refrence to it
 */
template <typename T> void masterHeap<T>::insert(T& val)
{
    // insert it to both high heaps while connecting both pointers entered to the heaps
    int inserted= highMaxHeap->Insert(&val, -1);
    highMinHeap->Insert(&val, inserted);
    highItemCount++;// update high part counter
    rebalance();
}

/**
 * @brief rebalances the heaps between the high part and low part
 * 
 * @tparam T - the type of the master heap need to have an > operator to work
 */
template <typename T> void masterHeap<T>::rebalance()
{
    if(highItemCount==lowItemCount+1) // happens when we insert and when we deletemin 
    {
        if(lowItemCount!=0)
        {
            const T* minHigh = highMinHeap->Top();// we get the max from low part
            const T* maxLow = lowMaxHeap->Top();// and min from high part
            if(*maxLow > *minHigh)// check if we need to replace them to keep the order correct
            {
                const T* min = highMinHeap->deleteTop(); // remove the min from high
                const T* max = lowMaxHeap->deleteTop();// remove the max from low

                // do the replacment
                int inserted = highMaxHeap->Insert(max, -1);
                highMinHeap->Insert(max, inserted);

                inserted = lowMinHeap->Insert(min, -1);
                lowMaxHeap->Insert(min, inserted);
            }
        }
    }
    else if(highItemCount==lowItemCount)// happens after some deletemax
    {
        if(lowItemCount!=0)
        {
            const T* minHigh = highMinHeap->Top();// we get the max from low part
            const T* maxLow = lowMaxHeap->Top();// and min from high part
            if(*maxLow > *minHigh)// check if we need to replace them to keep the order correct
            {
                const T* min = highMinHeap->deleteTop(); // remove the min from high
                const T* max = lowMaxHeap->deleteTop();// remove the max from low

                // do the replacment
                int inserted = highMaxHeap->Insert(max, -1);
                highMinHeap->Insert(max, inserted);

                inserted = lowMinHeap->Insert(min, -1);
                lowMaxHeap->Insert(min, inserted);
            }
        }
    }
    else if(highItemCount+1==lowItemCount)//happens in some deleteMax
    {
        // we move the max from the low group the high group
        const T* max = lowMaxHeap->deleteTop();
        int inserted = highMinHeap->Insert(max, -1);
        highMaxHeap->Insert(max, inserted);
        highItemCount++;
        lowItemCount--;
    }
    else// happens every second insert this is basicly highItemCount-lowItemCount==2
    {
        // we move one from high group to low group - the min one
        const T* min = highMinHeap->deleteTop();
        int inserted = lowMinHeap->Insert(min, -1);
        lowMaxHeap->Insert(min, inserted);
        highItemCount--;
        lowItemCount++;
    }
}

/**
 * @brief the total item count in the struct
 * 
 * @tparam T - the type of the master heap need to have an > operator to work
 */
template <typename T> int masterHeap<T>::getItemCount()
{
    return lowItemCount+highItemCount;
}
