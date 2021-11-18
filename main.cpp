#include <iostream>
#include "inputOutput.h"
#include "subSumVersions.h"

using std::cin;
using std::cout;

int main()
{

    inputFromUserStruct *input = inputFromUser();

    cout << "the number is " << input->number << '\n';
    cout << "the n is " << input->n << '\n';


    vector<subSumPair>* res = subSumRecursiveWrap(input->arr, input->n, input->number);

    for(auto& pair: *res)
    {
        cout << pair.num1 << " " << pair.num2 << '\n';
    }
    
    res->clear();
    delete res;

    system("pause");

}