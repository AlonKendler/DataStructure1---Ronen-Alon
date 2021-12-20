#include <iostream>
//#include "heap.h"
#include "treeNode.h"

using std::cin;
using std::cout;

int main()
{
    int N;
    cout << "enter number of values" << "\n";
    cin >> N;

    TreeNode<int>* head=nullptr;
    TreeNode<int>* current = nullptr;

    for(int i=0;i<N;i++)
    {
        int t;
        cin >> t;
        if(head)
        {
            current->setLeft(new TreeNode<int>());
            current=current->getLeft();
            current->setData(t);
        }
        else
        {
            head = new TreeNode<int>();
            head->setData(t);
            current=head;
        }
    }
    head->print();
}