#include <iostream>
//#include "heap.h"
#include "heap.h"

using std::cin;
using std::cout;

int main()
{
    int N;
    cout << "enter number of values" << "\n";
    cin >> N;

    heap<int>* maxHeap = new heap<int>(nullptr);
    heap<int>* minHeap = new heap<int>(false, maxHeap);
    maxHeap->setBro(minHeap);
    for(int i=0;i<N;i++)
    {
        int t;
        cin >> t;
        TreeNode<int>* res=maxHeap->Insert(t, nullptr);
        minHeap->Insert(t, res);
    }

    for(int i=0;i<N;i++)
    {
        maxHeap->print();
        minHeap->print();

        TreeNode<int>* max = maxHeap->deleteTop();
        TreeNode<int>* min = minHeap->deleteTop();

        maxHeap->print();
        minHeap->print();
        
        cout << "max is: " << max->getData() << '\n';
        cout << "min is " << min->getData() << '\n';
        delete max;
        delete min;
    }
}