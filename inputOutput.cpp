#include "inputOutput.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

inputFromUserStruct *inputFromUser()
{
    inputFromUserStruct *input = new inputFromUserStruct();

    char line_feed=0;

    if (!(cin >> input->n))
    {
        cout << "wrong input";
        exit(1);
    }

    line_feed = cin.get();
    if(line_feed =='\r')
    {
        line_feed = cin.get();
    }
    if(line_feed!='\n')
    {
        cout << "wrong input";
        exit(1);
    }

    if (input->n <= 0)
    {
        cout << "wrong input";
        exit(1);
    }

    // inpt ARR
    // allocate memory to array
    input->arr = new int[input->n];

    for (int i = 0; i < input->n; i++)
    {
        if (cin.eof() || !(cin >> input->arr[i]) || input->arr[i]<=0)
        {
            cout << "wrong input";
            exit(1);
        }
    }

    line_feed = cin.get();
    if(line_feed =='\r')
    {
        line_feed = cin.get();
    }
    if(line_feed!='\n')
    {
        cout << "wrong input";
        exit(1);
    }

    // input number
    if (!(cin >> input->number) || input->number<=0)
    {
        cout << "wrong input";
        exit(1);
    }

    return input;
}