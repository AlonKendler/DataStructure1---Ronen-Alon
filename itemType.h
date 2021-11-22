#pragma once
#include <stdlib.h>

enum Type
{
    TypeInt,
    TypeAddress
};

class ItemType
{
private:
    int data;
    Type t;
public:
    ItemType(int number);
    ~ItemType();
    int getInt();
};