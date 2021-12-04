#include <iostream>
#include "inputOutput.h"
#include "subSumVersions.h"
#include "subSumFuncTimer.h"

using std::cin;
using std::cout;
using std::string;

void printResult(vector<subSumPair> *res, string text)
{
    cout << text;
    for (auto &pair : *res)
    {
        cout << '\n';
        cout << pair.num1 << " " << pair.num2;
    }
}

int main()
{
    inputFromUserStruct *input = inputFromUser();

    vector<subSumPair> *resIterative = funcTimer(subSumIterrative, "subSumIterrative", input->arr, input->n, input->number);
    printResult(resIterative, "Iterative:");
    cout << "\n\n";

    vector<subSumPair> *resRecursive = funcTimer(subSumRecursiveWrap, "subSumRecursiveWrap", input->arr, input->n, input->number);
    printResult(resRecursive, "Recursive:");
    cout << "\n\n";

    vector<subSumPair> *resEmulated = funcTimer(subSumRecursiveEmulated, "subSumRecursiveEmulated", input->arr, input->n, input->number);
    printResult(resEmulated, "Recursion implemented using stack:");

    resIterative->clear();
    delete resIterative;
    resRecursive->clear();
    delete resRecursive;
    resEmulated->clear();
    delete resEmulated;
}
