#ifndef ALGORITHM_H
#include <iostream>
#include <iomanip>
#include <string>


int BinarySearch(int A[], int hp, int lp, int x) {
	if (lp > hp) {
		return -1;
	}

	int midpoint = (hp + lp) / 2;
	if (A[midpoint] == x) {
		return A[midpoint];
	} else if (A[midpoint] < x) {
		return BinarySearch(A, lp, midpoint, x);
	} else if (A[midpoint] > x) {
		return BinarySearch(A, midpoint, hp, x);
	}
}

#endif // !ALGORITHM_H
#pragma once