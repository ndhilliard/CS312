#include <iostream>
#include <string>

using namespace std;

// task 1
bool IsRight(int a, int b, int c) {
	if (a > b) {
		int t = a;
		a = b;
		b = t;
	}
	if (b > c) {
		int t = b;
		b = c;
		c = t;
	}
	if (a > b) {
		int t = a;
		a = b;
		b = t;
	}
	if (a * a + b * b == c * c) {
		return true;
	}
	else {
		return false;
	}
}

// task 2
void FindFactors(int a) {
	if (a <= 0) {
		return;
	}
	
	cout << "Factors of " << a << " are: ";
	for (int i = 1; i <= a; i++) {
		if (a % i == 0) {
			cout << i << " ,";
		}
	}
}

// task 3
int FindMax(int A[]) {
	int max = A[0];

	for (int i = 1; i < sizeof(A); i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}

	return max;
}

// task 4

int SmallestPrime(int a) {
	if (a <= 1 || a > 1000) {
		return 0;
	}
	int i;
	for (i = 2; i <= a; i++) {
		if (a % i == 0) {
			for (int j = 2; j < i; j++) {
				if (i % j == 0) {
					break;
				}
			}

		}
	}

	return i;
}

// task 5