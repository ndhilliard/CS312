#include <iostream>
using namespace std;

int findMax(int A[], int B[]) {
	int maxValue = A[0];

	for (int i = 1; i < sizeof(A); i++) {
		if (A[i] > maxValue) {
			maxValue = A[i];
		}
	}

	for (int i = 0; i < sizeof(B); i++) {
		if (B[i] > maxValue) {
			maxValue = B[i];
		}
	}

	return maxValue;
}

int main() {
	int A[] = { 1, 3, 5, 7, 9 };
	int B[] = { 2, 4, 6, 8, 10 };
	cout << "The max value is: " << findMax(A, B) << endl;
	return 0;
}