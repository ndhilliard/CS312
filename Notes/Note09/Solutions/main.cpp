#include "Pair.h"

int main()
{
    std::string file;
    std::cout << "Enter a file: ";
    std::cin >> file;
    aap::PairArray A = aap::frequency(file);
    std::cout << A << "\n";

    aap::PairTree B(A[0]), C(A[1]), D(A[2]);
    std::cout << B << "\n" << C << "\n" << D << "\n\n";
    B.addLeft(C);
    B.addRight(D);
    std::cout << B << "\n";

    
    return 0;
}