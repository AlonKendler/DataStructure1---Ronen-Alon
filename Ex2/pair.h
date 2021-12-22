#pragma once
#include <string>

using std::string;

class pair
{
private:
    int key;
    string value;
public:
    pair(int key, string value);

    int getKey() const;
    string getValue() const;
    void setKey(int key);
    void setValue(int key);
    
    bool operator>(const pair& p2) const;
};