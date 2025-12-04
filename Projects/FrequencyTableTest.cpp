#include <iostream>
#include "FrequencyTable.h"

int main() {
	FrequencyTable f;

	f.loadFile("input.txt");
	std::cout << f << std::endl;

	return 0;
}