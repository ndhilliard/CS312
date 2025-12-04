#ifndef HUFFMANENCODER_H
#define HUFFMANENCODER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Object.h"
#include "BiTree.h"
#include "Pair.h"
#include "HuffmanTree.h"

class HuffmanEncoder : public aap::Object {

private:
	std::string codes[256];

	void buildCodes(aap::BiTree<Pair>* node, const std::string& path) {

		if (node == nullptr) {
			return;
		}

		if (node->left == nullptr && node->right == nullptr) {

			std::string key = node->data.getKey();
			if (key.size() == 1) {
				unsigned char c = key[0];
				codes[c] = path;
			}
			return;
		}

		buildCodes(node->left, path + "0");

		buildCodes(node->right, path + "1");
	}

public:

	HuffmanEncoder() {}

	void generate(const HuffmanTree& ht) {

		for (int i = 0; i < 256; i++) {
			codes[i] = "";
		}

		aap::BiTree<Pair>* root = ht.getRoot();
		if (root != nullptr) {
			buildCodes(root, "");
		}
	}

	std::string endcodeFile(const std::string& filename) {
		std::ifstream in(filename);
		if (!in) {
			return "";
		}

		std::stringstream out;
		char ch;
		
		while (in.get(ch)) {

			if (std::isalpha(ch)) {
				ch = std::tolower(ch);

				unsigned char c = static_cast<unsigned char>(ch);

				if (c <= 32 || c == 127) {
					continue;
				}
				out << codes[c];
			}
		}
		return out.str();
	}

	void save(const std::string& filename, const std::string& text) {
		std::ofstream out(filename);
		out << text;
	}

	std::string toString() const override {
		std::stringstream out;

		for (int i = 0; i < 256; i++) {
			if (codes[i] != "") {
				out << (char)i << ": " << codes[i] << "\n";
			}
		}

		return out.str();
	}
};
#endif // !HUFFMANENCODER_H
