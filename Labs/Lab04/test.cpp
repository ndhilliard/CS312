#include <iostream>
#include <string>
#include "Algorithm.h"

using namespace aa;
using namespace std;

int main() {

	Heap<Pair<char>> A;
	A.heapView(true);

	Enqueue(A, Pair<char>(3, 'A'));
	cout << A << endl;

	Enqueue(A, Pair<char>(4, 'B'));
	cout << A << endl;

	Enqueue(A, Pair<char>(3, 'C'));
	cout << A << endl;

	Enqueue(A, Pair<char>(2, 'D'));
	cout << A << endl;

	Enqueue(A, Pair<char>(1, 'E'));
	cout << A << endl;

	Enqueue(A, Pair<char>(2, 'F'));

	return 0;
}