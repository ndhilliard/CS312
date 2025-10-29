#include <iostream>

using namespace std;

// i feel like this shouldve broken this up into smaller functions...
static double InterquartileRange(int A[], int n) {

    for (int i = 0; i < n; ++i) {            
        int m = i;
        for (int j = i + 1; j < n; ++j) { 
            if (A[m] > A[j]) {
                m = j;                       
            }
        }

        if (m != i) { 
            int t = A[i]; 
            A[i] = A[m];
            A[m] = t;
        }
    }

  
    int l_lo = 0, l_hi = (n / 2) - 1;
    int u_lo = (n % 2 == 0) ? (n / 2) : (n / 2 + 1);
    int u_hi = n - 1;

  
    int m1 = (l_hi >= l_lo) ? (l_hi - l_lo + 1) : 0;

 
    double q1 = 0.0;
    if (m1 % 2 == 0) {

        int a = A[l_lo + (m1 / 2) - 1];
        int b = A[l_lo + (m1 / 2)];
        q1 = (a + b) / 2.0;
    } else { 

        q1 = A[l_lo + (m1 / 2)];
    }


    int m2 = (u_hi >= u_lo) ? (u_hi - u_lo + 1) : 0;


    double q3 = 0.0;
    if (m2 % 2 == 0) { 

        int a = A[u_lo + (m2 / 2) - 1];
        int b = A[u_lo + (m2 / 2)];
        q3 = (a + b) / 2.0;
    } else {
        q3 = A[u_lo + (m2 / 2)];
    }
    return q3 - q1;
}

// thank you for the extension!
int main() {
    int A[] = { 3,2,8,5,1,7,4,6 };
    int B[] = { 6,3,2,9,4,5,7,1,8 };

    int nA = sizeof(A) / sizeof(A[0]);
    int nB = sizeof(B) / sizeof(B[0]);

    cout << "Array A IQR: " << InterquartileRange(A, nA) << '\n';
    cout << "Array B IQR: " << InterquartileRange(B, nB) << '\n';

    return 0;
}