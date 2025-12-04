#ifndef TREEPRINTER_H
#define TREEPRINTER_H

#include <iostream>
#include <string>
#include <sstream>
#include "BiTree.h"

template <typename T>
void print(aap::BiTree<T>* root, std::stringstream& out) {

	if (root != nullptr) {

		out << "(" << root->data << " ";
		print(root->left, out);
		print(root->right, out);
		out << ")";
	}
}

#endif // !TREEPRINTER_H