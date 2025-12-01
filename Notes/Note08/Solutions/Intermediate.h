#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H

namespace aai
{
    template <typename T>
    const T& Maximum(T A[], int n)
    {
        T mx;
        int idx;

        if(n % 2 != 0)
        {
            mx = A[0];
            idx = 1;
        }
        else 
        {
            if(A[0] > A[1]) {mx = A[0];}
            else {mx = A[1];}
            idx = 2;
        }
        T mx = A[0], t;

        for(int i = idx;i < n;i += 2)
        {
            if(A[i] > A[i+1]) {t = A[i];}
            else {t = A[i+1];}
            if(mx < t) {mx = t;}
        }
        return mx;
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
}

#endif 

/*
A = [1,2,3,4,5,6,7]
     0 1 2 3 4 5 6
mx = 1;
[2,3]
[4,5]
[6,7]
even 
A = [1,2,3,4,5,6,7,8]
     0 1 2 3 4 5 6 7
mx = 2;
[3,4] (2,3)
[5,6] (4,5)
[7,8] (6,7)

*/