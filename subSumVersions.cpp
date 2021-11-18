#include "subSumVersions.h"


void subSumRecursive(int arr[], int size, int x, int y, vector<subSumPair>& res);


vector<subSumPair>* subSumIterrative(int arr[], int size, int x)
{
    vector<subSumPair> *res_vector = new vector<subSumPair>();

    for(int first=0;first<size-1;first++)
    {
        for(int second=first+1;second<size;second++)
        {
            if(arr[first]+arr[second]==x)
            {
                res_vector->push_back(subSumPair(arr[first], arr[second]));
            }
        }
    }

    return res_vector;
}

vector<subSumPair>* subSumRecursiveWrap(int arr[], int size, int x)
{
    vector<subSumPair> *res_vector = new vector<subSumPair>();

    subSumRecursive(arr,size,x,0,(*res_vector));

    return res_vector;
}

void subSumRecursive(int arr[], int size, int x, int y, vector<subSumPair>& res)
{

    if(size==1 && y!=0)
    {
        if(x==y+arr[0])
        {
            res.push_back(subSumPair(y,arr[0]));
        }
    }
    else if(size!=1)
    {
        if(y!=0)
        {
            if(y+arr[size-1]==x)
            {
                res.push_back(subSumPair(y,arr[size-1]));
            }
            subSumRecursive(arr,    size-1, x,  y,              res);
        }
        else
        {
            subSumRecursive(arr,    size-1, x,  arr[size-1],    res);
            subSumRecursive(arr,    size-1, x,  0,              res);
        }
    }
}

