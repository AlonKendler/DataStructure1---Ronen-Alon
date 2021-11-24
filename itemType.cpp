#include "itemType.h"

ItemType::ItemType(int size, int x, int y, address adr): size(size), x(x), y(y), adr(adr)
{

}

ItemType::ItemType()
{
    size = x = y = 0;
    adr = START;
}

ItemType::~ItemType()
{

}

address ItemType::getAdress() const
{
    return this->adr;
}

int ItemType::getX() const
{
    return x;
}

int ItemType::getY() const
{
    return y;
}

int ItemType::getSize() const
{
    return size;
}

void ItemType::setAdr(address adr)
{
    this->adr = adr;
}