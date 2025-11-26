#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cctype>
#include <string>

// task 1
template <typename T>
std::string toString(const std::vector<T>& vec) {
	std::ostringstream out;
	out << "[";

	for (int i = 0; i < vec.size(); i++) {
		out << vec[i];
		if (i < (int)vec.size() - 1) {
			out << ", ";
		}
	}

	out << "]";
	return out.str();
}

// task 2
template <typename T, typename Hash>
void HashCountSort(std::vector<T>& A, Hash hash, int k) {
	int n = A.size();
	std::vector<int> C(k, 0);
	std::vector<T> B(n);

	for (int i = 0; i < n; i++) {
		C[hash(A[i])] += 1;
	}

	for (int i = 1; i < k; i++) {
		C[i] = C[i] + C[i - 1];
	}

	for (int i = n - 1; i >= 0; i--) {
		int idx = hash(A[i]);
		B[C[idx] - 1] = A[i];
		C[idx] -= 1;
	}

	for (int i = 0; i < n; i++) {
		A[i] = B[i];
	}
}

#endif // !ALGORITHM_H
