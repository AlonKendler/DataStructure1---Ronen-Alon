#include "inputOutput.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool isStringValidNumber(string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }
    return true;
}

inputFromUserStruct *inputFromUser()
{
    inputFromUserStruct *input = new inputFromUserStruct();
    string strN, strNumber;

    // input arr size
    cin >> strN;
    if (!isStringValidNumber(strN))
    {
        cout << "wrong input" << endl;
        exit(1);
    }
    input->n = stoi(strN);

    if (input->n <= 0)
    {
        cout << "wrong input" << endl;
        exit(1);
    }

    // inpt ARR
    // allocate memory to array
    string *stringArr = new string[input->n];
    input->arr = new int[input->n];

    for (int i = 0; i < input->n; i++)
    {
        cin >> stringArr[i];
        if (!isStringValidNumber(stringArr[i]))
        {
            cout << "wrong input" << endl;
            exit(1);
        }
    }
    // pass stringArr to numericArr
    for (int i = 0; i < input->n; i++)
    {
        input->arr[i] = stod(stringArr[i]);
    }

    delete[] stringArr;

    // input number
    cin >> strNumber;
    if (!isStringValidNumber(strNumber))
    {
        cout << "wrong input" << endl;
        exit(1);
    }
    input->number = stoi(strNumber);

    return input;
}