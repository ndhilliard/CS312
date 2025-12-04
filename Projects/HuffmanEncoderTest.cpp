#include <iostream>
#include "FrequencyTable.h"
#include "HuffmanTree.h"
#include "HuffmanEncoder.h"

int main() {

	FrequencyTable ft;
	ft.loadFile("encoderTest.txt");
	std::cout << "Frequency Table: " << ft << "\n\n\n";

	HuffmanTree ht;
	ht.build(ft);

	HuffmanEncoder enc;
	enc.generate(ht);

	std::cout << "Code Table: " << "\n\n\n";

	std::string encoded = enc.endcodeFile("encoderTest.txt");
	std::cout << "\nEncoded Text: \n" << encoded << "\n";

	enc.save("EncodedOutput.txt", encoded);

	std::cout << "\nEncoded output saved to EncodedOutput.txt\n";

	return 0;
}