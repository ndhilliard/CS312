#ifndef COUNT_H
#define COUNT_H

#include <cctype> //tolower(), toupper()
#include "Pair.h"

namespace aa 
{
    void DigitCountSort(int A[],int B[],int n)
    {
        int C[10];

        //initialize all counters to zero 
        for(int i = 0;i < 10;i += 1) 
        {
            C[i] = 0;
        }

        //counts each instance of the values
        for(int i = 0;i < n;i += 1)
        {
            C[A[i]] += 1;
        }

        //converts counts into running sums
        for(int i = 1;i < 10;i += 1)
        {
            C[i] = C[i] + C[i-1];
        }

        //Sorts array into copy array using running sums
        for(int i = n - 1;i >= 0;i -= 1)
        {
            B[C[A[i]]-1] = A[i];
            C[A[i]] -= 1;  
        }
    }

    template <typename T>
    void DigitPairCountSort(Pair<T> A[],Pair<T> B[],int n)
    {
        int C[10];

        //initialize all counters to zero 
        for(int i = 0;i < 10;i += 1) 
        {
            C[i] = 0;
        }

        //counts each instance of the values
        for(int i = 0;i < n;i += 1)
        {
            C[A[i].key()] += 1;
        }

        //converts counts into running sums
        for(int i = 1;i < 10;i += 1)
        {
            C[i] = C[i] + C[i-1];
        }

        //Sorts array into copy array using running sums
        for(int i = n - 1;i >= 0;i -= 1)
        {
            B[C[A[i].key()]-1] = A[i];
            C[A[i].key()] -= 1;  
        }
    }

        int index(char ch) {
        return tolower(ch - 'a');
    }
    void LetterCountSort(std::string A, std::string& B)
    {
        int C[26];
		int n = A.length();

        for (int i = 0; i < 26; i++) {

            C[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            C[index(A[i])] += 1;
        }

        for (int i = 1; i < 26; i++) {
            C[i] = C[i] + C[i - 1];
		}

        for (int i = n - 1; i >= 0; i--) {
            B[C[index(A[i])] - 1] = A[i];
            C[index(A[i])] -= 1;
        }

    }

}
}

#endif
