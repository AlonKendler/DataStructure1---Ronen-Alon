#include "subSumFuncTimer.h"

vector<subSumPair>* funcTimer(vector<subSumPair>* (*func)(int*, int, int),const char* func_name, int arr[], int size, int x)
{
    string file_name(func_name);
    auto start = high_resolution_clock::now(); 
 
    // unsync the I/O of C and C++.  
    ios_base::sync_with_stdio(false); 
    
    vector<subSumPair> *res=func(arr, size, x); 
    

    auto end = high_resolution_clock::now(); 
    
    // Calculating total time taken by the program.  
    double time_taken = 
    duration_cast<nanoseconds>(end - start).count(); 
    
    time_taken *= 1e-9; 
    
    file_name = file_name + "Measure.txt"; 
    ofstream myfile(file_name); // The name of the file 
    
    myfile << "Time taken by function " << func_name << " is : " << fixed 
    << time_taken << setprecision(9); 
    myfile << " sec" << '\n'; 
    myfile.close();
    return res;
}