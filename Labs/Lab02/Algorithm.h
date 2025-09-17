#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double movingAverage(const double A[], double n, double t, double B[]) {
	if (!A[] || !B[]) {
		return 0;
	}
	if (n <= 0 || t <= 0 || t > n) {
		return 0;
	}
	for (int i = 0; i <= n - t + 1; i++) {
		int sum = 0;
		for (int j = 0; j <= t - 1; j++) {
			sum = sum + A[i + j];
		}
		B[i] = sum / t;
	}
}

return B;

#endif // !ALGORITHM_H
