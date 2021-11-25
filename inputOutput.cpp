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

    //input arr size (var of n)
    cout << "Enter n: ";
    cin >> strN;
    if (!isStringValidNumber(strN))
    {
        cout << "wrong input" << endl;
        exit(1);
    }
    input->n = stoi(strN);

    if(input->n<=0)
    {
        cout << "wrong input" << endl;
        exit(1);
    }

    //inpt ARR
    //allocate memory to array
    string *stringArr = new string[input->n];
    input->arr = new int[input->n];

    cout << "inputing array - Enter " << input->n << " numbers: ";
    for (int i = 0; i < input->n; i++)
    {
        cin >> stringArr[i];
        if (!isStringValidNumber(stringArr[i]))
        {
            cout << "arr number at index:" << i << "wrong input" << endl;
            exit(1);
        }
    }
    //pass stringArr to numericArr
    for (int i = 0; i < input->n; i++)
    {
        input->arr[i] = stod(stringArr[i]);
    }

    delete[] stringArr;

    //input number
    cout << "Enter number: ";
    char *last_input = new char[21];
    cin.getline(last_input, 20);
    strN.assign(last_input);
    if (!isStringValidNumber(strN))
    {
        cout << "wrong input" << endl;
        exit(1);
    }
    input->number = stoi(strN);

    return input;
}