#include "Quick.h"

int main()
{
    int A[] = {5,7,8,-5,2,10,100,-1,15,8};
    int B[] = {100,99,82,74,60,52,40,32,25,12};
    std::cout << "Original Array: "; 
    Print(A,10);
    std::cout << "\n";
    Quicksort(A,10);
    std::cout << "Final Array: ";
    Print(A,10);
    std::cout << "\n\n\n";
    std::cout << "Original Array: "; 
    Print(B,10);
    std::cout << "\n";
    Quicksort(B,10);
    std::cout << "Final Array: ";
    Print(B,10);
    std::cout << "\n";

    return 0;
}