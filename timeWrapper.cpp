#include "timeWrapper.h"

using namespace std;

void TimeWrapper()
{

    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    fun(); // Here you put the name of the function you wish to measure
    auto end = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    double time_taken =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    ofstream myfile("Measure.txt"); // The name of the file
    myfile << "Time taken by function <name-of-fun> is : " << fixed
           << time_taken << setprecision(9);
    myfile << " sec" << endl;
    myfile.close();
}