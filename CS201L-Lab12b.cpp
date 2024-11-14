// CS201L-Lab12b.cpp : This file contains the 'main' function. Program execution begins and ends there.
// GUNNER PACE

#include "Functions.h"

int main()
{
    // File validation
    ifstream input("input.txt");
    ofstream out("output.txt");
    if (!input.good() || !out.good()) {
        cout << "FILE ERROR: Could not validate file opening." << endl;
        return 1;
    }

    cout << "Welcome to the World of Recursion\n";

    inFileExecution(input, out);

    cout << "Execution completed successfully.\n";

    return 0;
}

