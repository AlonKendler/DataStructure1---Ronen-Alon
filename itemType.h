#pragma once
#include <stdlib.h>

enum address
{
    START,
    AFTER_CALL1,
    AFTER_CALL2,
    AFTER_CALL3
};

class ItemType
{
private:
    int size; 
    int x; 
    int y;
    address adr;
public:
    explicit ItemType();
    ItemType(int size, int x, int y, address adr);
    ~ItemType();
    address getAdress() const;
    int getX() const;
    int getY() const;
    int getSize() const;
    void setAdr(address adr);
};