#include <iostream>
#include <string>
#include <sstream>
#include "Brute.h"
#include "Divide.h"

template <typename T>
std::string print(T A[],int n)
{
    std::stringstream out;

    out << "[";

    for(int i = 0;i < n;i += 1)
    {
        out << A[i];

        if(i + 1 < n) {out << ",";}
    }
    out << "]";
    return out.str();
}

int main()
{
    double A[3][5] = {{1,8,15,9,12},{-5,-2,3,10,-1},{-7,-4,-10,-12,-2}};
    int lo, hi;

    std::cout << "Brute Runs\n";
    for(int i = 0;i < 3;i += 1)
    {
        lo = 0;
        hi = 4;
        std::cout << print(A[i],5) << "\n";
        std::cout << "the maximum subarray of the above array has a sum of ";
        std::cout << brute::MaxSubArray(A[i],lo,hi) << "\non the interval [";
        std::cout << lo << "," << hi << "]\n\n";
    }

    std::cout << "\nDivide Runs\n";
    for(int i = 0;i < 3;i += 1)
    {
        lo = 0;
        hi = 4;
        std::cout << print(A[i],5) << "\n";
        std::cout << "the maximum subarray of the above array has a sum of ";
        std::cout << divide::MaxSubArray(A[i],lo,hi) << "\non the interval [";
        std::cout << lo << "," << hi << "]\n\n";
    }

    return 0;
}