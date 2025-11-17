#ifndef QUICK_H
#define QUICK_H

#include <iostream>
#include <string>

template <typename T>
void Print(T A[],int size)
{
    std::cout << "[";

    for(int i = 0;i < size;i += 1)
    {
        std::cout << A[i];

        if(i+1 < size) {std::cout << ",";}
    }
    std::cout << "]";
}

template <typename T>
void Print(T A[],int s,int e)
{
    std::cout << "[";

    for(int i = s;i <= e;i += 1)
    {
        std::cout << A[i];

        if(i+1 <= e) {std::cout << ",";}
    }
    std::cout << "]";
}
/*
A : an array
p : start index of subarray of A
r : end index of subarray of A
*/
template <typename T>
int Partition(T A[],int p,int r)
{
    int pi = A[r]; //pivot 
    int i = p - 1; // end index of less than pivot subarray 
    T t; //temporary variable 

    for(int j = p;j < r;j += 1)
    {
        if(A[j] <= pi)
        {
            i += 1;
            t = A[j];
            A[j] = A[i];
            A[i] = t;
        }
    }

    t = A[i+1];
    A[i+1] = pi;
    A[r] = t;
    return (i + 1);
}

/*
A : the array
p : start index 
r : end index
*/
template <typename T>
void Quicksort(T A[],int p,int r)
{
    if(p < r)
    {
        int q = Partition(A,p,r);
        std::cout << "Partition(" << p << "," << r << "): ";
        Print(A,p,r);
        std::cout << " pivot: " << A[q] << "\n";
        Quicksort(A,p,q-1);
        Quicksort(A,q+1,r);
    }
}

/*
A : the array
n : array size 
*/
template <typename T>
void Quicksort(T A[], int n)
{
    Quicksort(A,0,n-1);
}

#endif