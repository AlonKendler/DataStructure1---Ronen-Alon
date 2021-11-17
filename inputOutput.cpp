#include "inputOutput.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool isStringValidNumber(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }
    return true;
}

int inputNumber()
{
    string str;
    cin >> str;
    if (!isStringValidNumber(str))
    {
        throw "wrong input";
    }
    return stoi(str);
}
inputFromUserStruct *inputFromUser()
{
    inputFromUserStruct *input = new inputFromUserStruct();
    string strN, strNumber;

    try
    {

        // input n (arr size)
        cout << "Enter n: ";
        input->n = inputNumber();

        // input array
        string *stringArr = new string[input->n];
        input->arr = new int[input->n];

        cout << "inputing array - Enter " << input->n << " numbers: ";
        for (int i = 0; i < input->n; i++)
        {
            stringArr[i] = inputNumber();
        }

        for (int i = 0; i < input->n; i++)
        {
            input->arr[i] = stod(stringArr[i]); // pass stringArr to numericArr
        }

        // input number
        cout << "Enter number: ";
        input->number = inputNumber();

        delete[] stringArr;
    }
    catch (const std::exception &e)
    {
        cout << e.what();
        exit(12);
    }

    return input;
}