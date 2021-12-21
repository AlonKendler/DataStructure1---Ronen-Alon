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
}