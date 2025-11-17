#ifndef RADIX_H
#define RADIX_H

#include "Count.h"

namespace aa
{
    void RadixSort(int A[],int n,int d)
    {
        Pair<int>* B = new Pair<int>[n];
        Pair<int>* C = new Pair<int>[n];
        int m = 1;

        for(int i = 0;i < n;i += 1)
        {
            B[i] = Pair<int>(0,A[i]);
        }

        for(int i = 0;i < d;i += 1)
        {
            for(int i = 0;i < n;i += 1)
            {
                B[i].key() = B[i].value() / m % 10;
            }
            
            DigitPairCountSort(B,C,n);

            for(int i = 0;i < n;i += 1)
            {
                B[i] = C[i];
            }
            m *= 10;
        }

        for(int i = 0;i < n;i += 1)
        {
            A[i] = B[i].value();
        }

        delete[] B;
        delete[] C;
    }
}
#endif