#include <iostream>
#include <string>
#include <sstream>
#include "BiTree.h"
#include "TreePrinter.h"

int main() {

	std::stringstream out;
	aap::BiTree<int>* a = new aap::BiTree<int>(4);

	a->left = new aap::BiTree<int>(6);
	a->right = new aap::BiTree<int>(9);
	a->left->left = new aap::BiTree<int>(3);
	a->left->right = new aap::BiTree<int>(5);

	print(a, out);
	std::cout << out.str();

	aap::DelTree(a);
	return 0;

}