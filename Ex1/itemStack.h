#pragma once
#include "itemType.h"

class ItemStackNode
{
private:
    ItemType data;
    ItemStackNode *next;
public:
    ItemStackNode();
    ItemStackNode(ItemType item): data(item), next(nullptr) {}
    ItemStackNode(ItemType item, ItemStackNode* next): data(item), next(next) {}
    ~ItemStackNode();
    void makeDummy();
    bool isDummy();
    ItemStackNode* getNext();
    ItemType getData();
};


class ItemStack
{
private:
    ItemStackNode *top;
public:
    ItemStack();
    ~ItemStack();
    bool isEmpty();
    ItemType pop();
    void makeEmpty();
    void push(ItemType item);
};