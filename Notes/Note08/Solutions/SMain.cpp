#include <iostream>
#include <string>
#include "Simple.h"

template <typename T>
void print(T A[],int n)
{
    std::cout << "[";

    for(int i = 0;i < n;i += 1)
    {
        std::cout << A[i];

        if(i + 1 < n) {std::cout << ",";}
    }
    std::cout << "]";
}

int main()
{
    int a[10] = {12,20,33,50,72,12,31,92,21,89}, imx, imn; 
    std::string b[10] = {"first","second","third","fourth","fifth","sixth","seventh","eigth","nineth","tenth"}, smx, smn;

    print(a,10);
    std::cout << "\n" << aa::Maximum(a,10) << " " << aa::Minimum(a,10) << "\n";
    aa::MaxMin(a,10,imx,imn);
    std::cout << imx << " " << imn << "\n\n";
    print(b,10);
    std::cout << "\n" << aa::Maximum(b,10) << " " << aa::Minimum(b,10) << "\n";
    aa::MaxMin(b,10,smx,smn);
    std::cout << smx << " " << smn << "\n\n";

    return 0;
}