#include <iostream>
#include <vector>
#include <string>
#include "Algorithm.h"

using namespace std;

int charHash(char key) {
	if (isupper(key)) {
		return key - 'A';
	} else if (islower(key)) {
		return key - 'a';
	}
	return 26;
}

int intHash(int key) {
	return key % 4;
}

int main() {
	vector<char> A = {'R', 'e', 'I', 'N', 'V', 'O', 'K', 'E', 'S'};
	cout << "Task 3 test" << endl;
	cout << "Before: " << toString(A) << endl;
	HashCountSort<char>(A, charHash, 27);
	cout << "After: " << toString(A) << endl << endl;

	vector<int> B = { 28,52,99,53,41,71,84,83,32 };
	cout << "Task 4 test" << endl;
	cout << "Befor: " << toString(B) << endl;
	HashCountSort<int>(B, intHash, 10);
	cout << "After: " << toString(B) << endl;

	return 0;
}
