#include <iostream>
#include "masterHeap.h"

using std::cin;
using std::cout;

int main()
{
    int N;
    cout << "enter number of values" << "\n";
    cin >> N;

    masterHeap<int>* master=new masterHeap<int>();

    master->CreateEmpty();
    for(int i=0;i<N;i++)
    {
        int t;
        cin >> t;
        master->insert(t);
    }

    cout << master->deleteMax() << '\n';

    cout << master->median() << '\n';

    cout << master->min() << "max: " << master->max() << '\n';

    cout << master->deleteMin() << '\n';

}