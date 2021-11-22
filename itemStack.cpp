#include "itemStack.h"

ItemStack::ItemStack()
{
    top = new ItemStackNode();
}

ItemStack::~ItemStack()
{
    makeEmpty();
    delete top;
}

void ItemStack::makeEmpty()
{
    while(!isEmpty())
    {
        ItemType data=pop();
        data.~ItemType();
    }
}

ItemType ItemStack::pop()
{
    ItemType res = top->getData();
    ItemStackNode* nextTop = top->getNext();
    delete top;
    top = nextTop;
    return res;
}

bool ItemStack::isEmpty()
{
    return top->isDummy();

}

void ItemStack::push(ItemType item)
{
    ItemStackNode* add = new ItemStackNode(item, top);
    top = add;
}

bool ItemStackNode::isDummy()
{
    return next==nullptr;
}

ItemStackNode* ItemStackNode::getNext()
{
    return next;
}

ItemType ItemStackNode::getData()
{
    return data;
}

ItemStackNode::ItemStackNode(): data(0)
{
    makeDummy();
}

ItemStackNode::~ItemStackNode()
{
    data.~ItemType();
}

void ItemStackNode::makeDummy()
{
    this->data = ItemType(0);
    this->next = nullptr;
}
