#include <iostream>
#include "Pair.h"

int main() {
	Pair a("other", 5);

	for (int i = 0; i < 4; i++) {
		std::cout << a << "\n";
	}

	return 0;
}