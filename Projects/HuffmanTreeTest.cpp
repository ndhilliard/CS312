#include <iostream>
#include "HuffmanTree.h"
#include "FrequencyTable.h"
#include "TreePrinter.h"

int main() {

	FrequencyTable ft;

	ft.loadFile("Input.txt");

	std::cout << "Frequency Table:" << std::endl;

	HuffmanTree ht;
	ht.build(ft);

	std::cout << "Huffman Tree: \n";

	aap::BiTree<Pair>* root = ht.getRoot();

	// this doesnt really look that pretty...
	// so man ()))))) brackets...
	// i'll fix that later if i have time
	if (root != nullptr) {
		std::stringstream out;
		print(root, out);
		std::cout << out.str() << std::endl;
	}
	return 0;
}