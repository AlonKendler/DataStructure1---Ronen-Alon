#include "subSumVersions.h"



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