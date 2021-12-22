#include "pair.h"

pair::pair(int key, string value) : key(key), value(value) {}

int pair::getKey() const
{
    return key;
}

string pair::getValue() const
{
    return value;
}

void pair::setKey(int key)
{
    this->key = key;
}

void pair::setValue(int key)
{
    this->value = key;
}
