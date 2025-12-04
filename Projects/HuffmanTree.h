#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <string>
#include "Object.h"
#include "Pair.h"
#include "BiTree.h"
#include "FrequencyTable.h"
#include "Heap.h"

class HuffmanTree : public aap::Object {

private:
	aap::BiTree<Pair>* root;

public:

	HuffmanTree() : root(nullptr) {}

	~HuffmanTree() {
		if (root != nullptr) {
			aap::DelTree(root);
			root = nullptr;
		}
	}

	void build(const FrequencyTable& ft) {

		// if table is empty do nothing
		if (ft.getSize() == 0) {
			return;
		}
		// min heap
		Heap heap;
	
		// get frequency table
		Pair* A = ft.getTable();
		int n = ft.getSize();

		// create leaves for each character
		for (int i = 0; i < n; i++) {
			aap::BiTree<Pair>* node = new aap::BiTree<Pair>(A[i]);
			heap.push(node);
		}

		// merge until only one node remains
		while (heap.getSize() > 1) {

			// grab the 2 smallest nodes
			aap::BiTree<Pair>* a = heap.pop();
			aap::BiTree<Pair>* b = heap.pop();

			// merge the frequencies
			int sum = a->data.getValue() + b->data.getValue();
			Pair parentValue("", sum);

			// create new parent node and push it(salt and peppa?)
			aap::BiTree<Pair>* parent = new aap::BiTree<Pair>(parentValue);

			parent->left = a;
			parent->right = b;

			heap.push(parent);
		}
		root = heap.pop();
	}

	aap::BiTree<Pair>* getRoot() const {
		return root;
	}

	std::string toString() const override {
		return "HuffmanTree";
	}
};
#endif // !HUFFMANTREE_H
