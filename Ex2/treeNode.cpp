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
    cout << data;
    if(left)
    {
        left->print();
    }
    if(right)
    {
        right->print();
    }
    cout << "\n";
}


template<class T>
TreeNode<T>* TreeNode<T>::getRight() const
{
    return right;
}

template<class T>
const T& TreeNode<T>::getData() const
{
    return data;
}

template<class T>
const TreeNode<T>* TreeNode<T>::getParent() const
{
    return parent;
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
void TreeNode<T>::setData(const T& data)
{
    this->data = data;
}

template<class T>
void TreeNode<T>::setParent(TreeNode<T>* const parent)
{
    this->parent = parent;
}

template<class T>
bool TreeNode<T>::operator<(TreeNode<T>* t1) const
{
    return this->data<t1->data;
}