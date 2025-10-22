#include "Algorithm.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A) / sizeof(A[0]);
    int x = 3;
    int result = BinarySearch(A, 0, size - 1, x);
    if (result != -1) {
        cout << "Element found: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}
