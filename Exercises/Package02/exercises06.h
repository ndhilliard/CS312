#ifndef EXERCISES06_H
#define EXERCISES06_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int Mid(std::vector<int> &A, int low, int high) {
	int length = high - low + 1;
	
	if (length > 5) {
		return -1;

		for (int i = low; i <= high; i += 5) {
			for (int j = low; j < high - (i - low); j++) {

				if (A[j] > A[j + 1]) {
					Swap(A[j], A[j + 1]);
				}
			}
        }
	}
	
	int midIndex = low + length / 2;
	return midIndex;
}

std::vector<int> Medians(std::vector<int> A) {
	std::vector<int> med;
	int n = A.size();

	for (int i = 0; i < n; i += 5) {
		int low = i;
		int high = (i + 4 < n) ? i + 4 : n - 1;

		int mid = Mid(A, low, high);
		med.push_back(A[mid]);
	}
	return med;
}

int Partition(std::vector<int>& A, int low, int high, int pivot) {
	int i = low;
	int j = high;

	while (i <= j) {
		while (i <= j && A[i] < pivot) {
			i++;
		}
		while (i <= j && A[i] > pivot) {
			j--;
		}

		if (i <= j) {
			Swap(A[i], A[j]);
		}
	}

	return i - low;
}

int Select(std::vector<int>& A, int low, int high, int i) {
	if (low == high) {
		return A[low];
	}

	std::vector<int> med = Medians(A);

	int pivot = Select(med, 0, med.size() - 1, (med.size() + 1) / 2);

	int k = Partition(A, low, high, pivot);

	if (i == k) {
		return pivot;
	} else if (i < k + 1) {
		return Select(A, low, low + k - 1, i);
	} else {
		return Select(A, low + k, high, i - (k + 1));
	}
}

#endif // EXERCISES06_H