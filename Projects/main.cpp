#include <iostream>
#include <sstream>
#include "FrequencyTable.h"
#include "HuffmanEncoder.h"
#include "HuffmanTree.h"
#include "TreePrinter.h"

int main() {

	// create frequency table from input file
	FrequencyTable ft;
	ft.loadFile("input.txt");

	// display frequency table
	std::cout << "Frequency Table: " << std::endl;
	std::cout << ft << std::endl;

	// create huffmantree
	HuffmanTree ht;
	ht.build(ft);

	aap::BiTree<Pair>* root = ht.getRoot();

	// display huffman tree
	std::cout << "Huffman Tree: " << std::endl;

	if (root != nullptr) {
		std::stringstream out;
		print(root, out);
		std::cout << out.str() << std::endl;
	} else {
		std::cout << "ERROR: Tree is empty!" << std::endl;
	}

	// encode file
	HuffmanEncoder enc;
	enc.generate(ht);

	std::cout << "Code Table: " << std::endl;
	std::cout << enc << std::endl;

	// theres a typo endcodeFile should be encodeFile fix later...
	std::string encoded = enc.endcodeFile("input.txt");

	std::cout << "Encoded File: " << std::endl;
	std::cout << encoded << std::endl;

	enc.save("encoded.txt", encoded);

	std::cout << "Encoded file saved to 'encoded.txt'" << std::endl;

	return 0;
}