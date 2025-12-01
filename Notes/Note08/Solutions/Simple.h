#ifndef SIMPLE_H
#define SIMPLE_H

namespace aa
{
    template <typename T>
    const T& Maximum(T A[], int n)
    {
        int idx = 0; //T mx = A[0];

        for(int i = 1;i < n;i += 1)
        {
            if(A[idx] < A[i]) {idx = i;}
        }
        return A[idx]; //mx
    } 

    template <typename T>    
    const T& Minimum(T A[], int n)
    {
        int idx = 0; //T mn = A[0];

        for(int i = 1;i < n;i += 1)
        {
            if(A[idx] > A[i]) {idx = i;}
        }
        return A[idx]; //mn
    }
    
    template <typename T>
    void MaxMin(T A[],int n,T& mx,T& mn)
    {
        if(n >= 2)
        {
            if(A[0] > A[1])
            {
                mx = A[0];
                mn = A[1];
            }
            else 
            {
                mx = A[1];
                mn = A[0];
            }
        }

        for(int i = 2;i < n;i += 1)
        {
            if(mn > A[i]) {mn = A[i];}
            else if(mx < A[i]) {mx = A[i];}
        }
    }
}

#endif 