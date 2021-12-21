#include "treeNode.h"

template class TreeNode<int>;

template<class T>
TreeNode<T>* TreeNode<T>::getLeft() const
{
    return left;
}

template<class T>
void TreeNode<T>::print() const
{
    cout << data << ' ';
    if(left)
    {
        left->print();
    }
    if(right)
    {
        right->print();
    }
}

template<class T>
void TreeNode<T>::printInOrder() const
{
    if(left)
    {
        left->printInOrder();
    }
    cout << data << ' ';
    if(right)
    {
        right->printInOrder();
    }
}

template<class T>
TreeNode<T>* TreeNode<T>::getRight() const
{
    return right;
}

template<class T>
T* TreeNode<T>::getData() const
{
    return data;
}

template<class T>
TreeNode<T>* TreeNode<T>::getParent()
{
    return parent;
}

template<class T>
TreeNode<T>* TreeNode<T>::getTwin()
{
    return twin;
}

template<class T>
void TreeNode<T>::setLeft(TreeNode<T>* const left)
{
    this->left = left;
    if(left)
        left->parent = this;
}

template<class T>
void TreeNode<T>::setRight(TreeNode<T>* const right)
{
    this->right = right;
    if(right)
        right->parent=this;
}

template<class T>
void TreeNode<T>::setData(T* data)
{
    this->data = data;
}

template<class T>
void TreeNode<T>::setParent(TreeNode<T>* const parent)
{
    this->parent = parent;
}

template<class T>
void TreeNode<T>::setTwin(TreeNode<T>* const twin)
{
    this->twin = twin;
}