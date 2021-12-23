#include "heapItem.h"

template class heapItem<pair>;

template<class T>
T* heapItem<T>::getData() const
{
    return data;
}

template<class T>
int heapItem<T>::getTwin()
{
    return twinIndex;
}

template<class T>
void heapItem<T>::setData(const T* data)
{
    this->data = (pair*)data;
}

template<class T>
void heapItem<T>::setTwin(int twin)
{
    this->twinIndex = twin;
}

template<class T> bool heapItem<T>::operator!=(const heapItem<T> &cmp) const
{
    return this->data==cmp.data && twinIndex==cmp.twinIndex;
}
