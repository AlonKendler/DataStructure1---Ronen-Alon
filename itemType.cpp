#include "itemType.h"

ItemType::ItemType(int num)
{
    data = num;
    t = TypeInt;
}


ItemType::~ItemType()
{

}

int ItemType::getInt()
{
    return data;
}