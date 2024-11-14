#include "Functions.h"

bool isDigit(string& str) {
	return str.find_first_not_of("0123456789") == string::npos;
}

long factorialR(long value) {
	if (value < 0) return -1;
	if (value == 0) return 1;
	return value * factorialR(value - 1);
}

bool isPrimeR(int& value, int n) {
	if (n > sqrt(value)) return true;
	if (value % n == 0) return false;
	else return isPrimeR(value, ++n);
	return false; // Only executes if base case never returns
}

int sumR(vector<int> nums, int pos) {
	if (pos == nums.size()) return 0;
	return nums[pos] + sumR(nums, pos + 1);
}

bool palindromeR(string str, int left, int right) {
	if (left >= right) return true;
	if (str[left] != str[right-1]) return false;
	return palindromeR(str, left + 1, right - 1);
}

void reverseStringR(ofstream& out, string str) {
	if (str.size() < 1) return;
	reverseStringR(out, str.substr(1));
	out << str[0];
}

void inFileExecution(ifstream& input, ofstream& out) {
	vector<string> tokens;
	string line;

	while (getline(input, line)) { // Iterate through each line of input file
		tokens.clear();
		string token;
		stringstream ss(line);

		while (getline(ss, token, ',')) { // Load comma separated tokens into vector
			tokens.push_back(token);
		}

		try {
			if (tokens[0] == "factorialR") {
				if (!isDigit(tokens[1])) throw invalid_argument("Record contains invalid values: " + line);
				long value = stol(tokens[1]);
				out << "Factorial of " << tokens[1] << " = " << factorialR(value) << endl;
			}
			else if (tokens[0] == "isPrimeR") {
				if (!isDigit(tokens[1])) throw invalid_argument("Record contains invalid values: " + line);
				int value = stoi(tokens[1]);
				bool isPrime = isPrimeR(value, 2);
				out << value << " is ";
				if (!isPrime) out << "not ";
				out << "a prime number." << endl;
			}
			else if (tokens[0] == "palindromeR") {
				string str = tokens[1];
				bool isPalindrome = palindromeR(str, 0, str.size());
				out << str << " is ";
				if (!isPalindrome) out << "not ";
				out << "a palindrome." << endl;
			}
			else if (tokens[0] == "sumR") {
				vector<int> nums;
				for (auto i = 1; i < tokens.size(); ++i) {
					if (isDigit(tokens[i])) nums.push_back(stoi(tokens[i]));
					else throw invalid_argument("The value " + tokens[i] + " is invalid.");
				}
				out << "The sum of the values: ";
				for (auto i = 0; i < nums.size(); ++i) out << nums[i] << " ";
				out << "is " << sumR(nums, 0) << endl;
			}
			else if (tokens[0] == "reverseStringR") {
				string str = tokens[1];
				out << "The string " << str << " in reverse is: ";
				reverseStringR(out, str);
				out << endl;
			}
			else throw invalid_argument("The current command: " + tokens[0] + " is invalid.");
		}
		catch (invalid_argument& e) {
			out << e.what() << endl;
		}
	}
}