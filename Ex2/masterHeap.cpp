#include "masterHeap.h"

template class masterHeap<pair>;

template <typename T> void masterHeap<T>::CreateEmpty()
{
    highMaxHeap = new heap<T>(nullptr);
    highMinHeap = new heap<T>(false, highMaxHeap);
    highMaxHeap->setBro(highMinHeap);

    lowMaxHeap = new heap<T>(nullptr);
    lowMinHeap = new heap<T>(false, lowMaxHeap);
    lowMaxHeap->setBro(lowMinHeap);

    highItemCount=lowItemCount=0;
}

template <typename T> const T& masterHeap<T>::max()
{
    if(highItemCount!=0)
    {
        return highMaxHeap->Top();
    }
    else
    {
        throw std::out_of_range("empty heap");
    }
}

template <typename T> const T& masterHeap<T>::deleteMax()
{
    if(highItemCount!=0)
    {
        TreeNode<T>* removed = highMaxHeap->deleteTop();
        const T& data = *(removed->getData());
        delete removed;
        highItemCount--;
        rebalance();
        return data;
    }
    else
    {
        throw std::out_of_range("empty heap");
    }
}

template <typename T> const T& masterHeap<T>::min()
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
    else
    {
        throw std::out_of_range("empty heap");
    }
}

template <typename T> const T& masterHeap<T>::deleteMin()
{
    if(highItemCount!=0)
    {
        TreeNode<T>* removed = nullptr;
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
        
        const T& data = *(removed->getData());
        delete removed;
        rebalance();
        return data;

    }
    else
    {
        throw std::out_of_range("empty heap");
    }
}

template <typename T> const T& masterHeap<T>::median()
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
    else
    {
        throw std::out_of_range("empty heap");
    }
}

template <typename T> void masterHeap<T>::insert(T& val)
{
    TreeNode<T>* inserted= highMaxHeap->Insert(&val, nullptr);
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
            const T& minHigh = highMinHeap->Top();
            const T& maxLow = lowMaxHeap->Top();
            if(maxLow > minHigh)
            {
                TreeNode<T>* min = highMinHeap->deleteTop();
                TreeNode<T>* max = lowMaxHeap->deleteTop();

                TreeNode<T>* inserted = highMaxHeap->Insert(max->getData(), nullptr);
                highMinHeap->Insert(max->getData(), inserted);

                inserted = lowMinHeap->Insert(min->getData(), nullptr);
                lowMaxHeap->Insert(min->getData(), inserted);

                delete min;
                delete max;
            }
        }
    }
    else if(highItemCount==lowItemCount)
    {
        
    }
    else if(highItemCount+1==lowItemCount)
    {
        TreeNode<T>* max = lowMaxHeap->deleteTop();
        TreeNode<T>* inserted = highMinHeap->Insert(max->getData(), nullptr);
        highMaxHeap->Insert(max->getData(), inserted);
        highItemCount++;
        lowItemCount--;
    }
    else
    {
        TreeNode<T>* min = highMinHeap->deleteTop();
        TreeNode<T>* inserted = lowMinHeap->Insert(min->getData(), nullptr);
        lowMaxHeap->Insert(min->getData(), inserted);
        highItemCount--;
        lowItemCount++;
    }
}

template <typename T> 
int masterHeap<T>::getItemCount()
{
    return lowItemCount+highItemCount;
}
