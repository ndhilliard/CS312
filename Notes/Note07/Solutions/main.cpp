#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> // srand(), rand()
#include <ctime> // time()
#include "Count.h"
#include "Radix.h"

template <typename T>
std::string print(T A[],int n,char delimiter,std::string braces)
{
    std::stringstream out;

    out << braces[0];

    for(int i = 0;i < n;i += 1)
    {
        out << A[i];

        if(i + 1 < n) {out << delimiter;}
    }
    out << braces[1];
    return out.str();
}

int main() 
{
    srand(time(nullptr));

    aa::Pair<char> A[12], B[12];

    for(int i = 0;i < 12;i += 1) {A[i] = aa::Pair<char>(rand() % 10,'A' + (rand() % 26));}
    aa::DigitPairCountSort(A,B,12);
    std::cout << "A = " + print(A,12,',',"[]") + "\nB = " + print(B,12,',',"{}") + "\n";

    int C[12];

    for(int i = 0;i < 12;i += 1) {C[i] = rand() % 100;}

    std::cout << "C = " + print(C,12,',',"[]") + "\n";
    aa::RadixSort(C,12,2);
    std::cout << "C = " + print(C,12,',',"{}") + "\n";
    
    return 0;
}

