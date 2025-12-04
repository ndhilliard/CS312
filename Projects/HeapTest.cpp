#include <iostream>
#include <string>
#include "Heap.h"
#include "TreePrinter.h"
#include "BiTree.h"
#include "Pair.h"

int main() {

	Heap h;

	aap::BiTree<Pair>* n1 = new aap::BiTree<Pair>(Pair("a", 5));
	aap::BiTree<Pair>* n2 = new aap::BiTree<Pair>(Pair("b", 2));
	aap::BiTree<Pair>* n3 = new aap::BiTree<Pair>(Pair("c", 8));
	aap::BiTree<Pair>* n4 = new aap::BiTree<Pair>(Pair("d", 2));
	aap::BiTree<Pair>* n5 = new aap::BiTree<Pair>(Pair("e", 1));

	h.push(n1);
	h.push(n2);
	h.push(n3);
	h.push(n4);
	h.push(n5);

	while (!h.isEmpty()) {
		aap::BiTree<Pair>* node = h.pop();
		std::cout << node->data << std::endl;
	}

	return 0;
}

