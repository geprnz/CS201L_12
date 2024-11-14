#pragma once
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool isDigit(string& str);

void inFileExecution(ifstream& input, ofstream& output);

// PRE: Takes a long value
// POST: Returns factorial of value or -1 if value < 0
long factorialR(long value);

// PRE: Takes an int value, first call n=2
// POST: Checks values n up to value^1/2 
bool isPrimeR(int& value, int n);

// PRE: Takes vector of int, first call pos=0
// POST: Returns sum of all vector values
int SumR(vector<int> nums, int pos);

// PRE: Takes a string, first call left=0, right=str.size()
// POST: Returns bool value after checking ends of string each instance
bool palindromeR(string str, int left, int right);

// PRE: Takes output file and string
// POST: Outputs string reversed to output file
void reverseStringR(ofstream& out, string str);
