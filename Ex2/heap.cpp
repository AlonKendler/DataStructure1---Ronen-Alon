#include "heap.h"


const TreeNode* heap::Insert(Item t, TreeNode* twin)//returns where the Item is to set twins
{

}

const Item& heap::Top() const
{
    return head->getData();
}

void heap::fixHeap(TreeNode *borked)
{

}

TreeNode* heap::removeTop()
{
    TreeNode* top = head;
    tail->setLeft(head->getLeft());
    tail->setRight(head->getRight());
    head=tail;
    fixHeap(head);
    return top;
}