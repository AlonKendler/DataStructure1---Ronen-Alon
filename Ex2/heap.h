#include "treeNode.h"


class heap
{
    int (*cmp_func)(Item& const i1, Item& const i2);
    TreeNode* head;
    TreeNode* tail;
    int itemCount;
public:
    heap(int (*cmp_func)(Item& const i1, Item& const i2)): head(nullptr), tail(nullptr), cmp_func(cmp_func), itemCount(0){}

    const TreeNode* Insert(Item t, TreeNode* twin);//returns where the Item is to set twins
    const Item& Top() const;
    void fixHeap(TreeNode *borked);
    TreeNode* removeTop();
};