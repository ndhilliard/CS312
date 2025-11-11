#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <string>

namespace aa {
	template <class V>
	void Enqueue(Heap<Pair<V>>& A, const Pair<V>& x) {

		if (size() == length()) {
			return;
		}

		size_t i = A.size();
		A.size(A.size() + 1);

		A[i] = x;


		while (i != 0 && A[Parent(i)].Key() > A[i].Key()) {
			Pair<V> temp = A[i];
			A[i] = A[Parent(i)];
			A[Parent(i)] = temp;
			i = Parent(i);
		}
	}
}
#endif // !ALGORITHM_H

#pragma once
