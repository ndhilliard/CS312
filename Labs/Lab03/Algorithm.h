#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <iostream>
#include <iomanip>
#include <string>


int BinarySearch(int A[], int lp, int hp, int x) {
	if (lp > hp) {
		return -1;
	}

	int midpoint = lp + (hp - lp) / 2;

	if (A[midpoint] == x) {
		return midpoint;
	} else if (A[midpoint] < x) {
		return BinarySearch(A, midpoint +  1, hp, x);
	} else {
		return BinarySearch(A, lp, midpoint - 1, x);
	}
}

#endif // !ALGORITHM_H