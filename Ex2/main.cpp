#include <iostream>
#include "heap.h"

using std::cin;
using std::cout;

int main()
{
    int N;
    cout << "enter number of values" << "\n";
    cin >> N;

    heap<int>* h=new heap<int>();

    for(int i=0;i<N;i++)
    {
        int t;
        cin >> t;
        h->Insert(t);
    }
    cout << h << '\n';
}