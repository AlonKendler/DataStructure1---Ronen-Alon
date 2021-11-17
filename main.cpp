#include <iostream>
#include "inputOutput.h"

using std::cin;
using std::cout;

int main()
{

    inputFromUserStruct *input = inputFromUser();

    cout << "the number is" << input->number;
    cout << "the n is" << input->n;

    cout << "hello worldd\n";
    char a;
    cin >> a;
}