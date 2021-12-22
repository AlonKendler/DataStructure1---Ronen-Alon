#include <string>

using std::string;

class pair
{
private:
    int key;
    string value;

    pair(int key, string value);

    int getKey() const;
    string getValue() const;
    void setKey(int key);
    void setValue(int key);
};