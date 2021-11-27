#include <iostream>
#include "inputOutput.h"
#include "subSumVersions.h"
#include "subSumFuncTimer.h"

using std::cin;
using std::cout;
using std::string;

void printResult(vector<subSumPair> *res, string text)
{
    cout << text << '\n';
    for (auto &pair : *res)
    {
        cout << pair.num1 << " " << pair.num2 << '\n';
    }
}

int main()
{
    inputFromUserStruct *input = inputFromUser();

    vector<subSumPair> *resIterative = funcTimer(subSumIterrative, "subSumIterrative", input->arr, input->n, input->number);
    printResult(resIterative, "Iterative:");

    vector<subSumPair> *resRecursive = funcTimer(subSumRecursiveWrap, "subSumRecursiveWrap", input->arr, input->n, input->number);
    printResult(resRecursive, "Recursive:");

    vector<subSumPair> *resEmulated = funcTimer(subSumRecursiveEmulated, "subSumRecursiveEmulated", input->arr, input->n, input->number);
    printResult(resEmulated, "Recursion implemented using stack:");

    resIterative->clear();
    delete resIterative;
    resRecursive->clear();
    delete resRecursive;
    resEmulated->clear();
    delete resEmulated;

    system("pause");
}
