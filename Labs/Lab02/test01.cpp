#include "Algorithm.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main() {

	int A[] = { 1, 2, 3, 4, 5, 6 };
	const int n = sizeof(A) / sizeof(A[0]);
	int s = 3;
	double T[n];

	int m = MovingAverage(A, s, n, T);


	cout << "Test Case 1 \n";
	cout << "Dataset [";

	for (int i = 0; i < n; i++) {
		if (i) {
			cout << ", ";
		}
		cout << A[i];
	}

	cout << "]\n";

	cout << "Moving Average: [";

	for (int i = 0; i < m; i++) {
		if (i) {
			cout << ", ";
		}

		if (T[i] == static_cast<int>(T[i])) {
			cout << static_cast<int>(T[i]);
		} else {
			cout << T[i];
		}
	}
	cout << "]\n";

	return 0;
}
