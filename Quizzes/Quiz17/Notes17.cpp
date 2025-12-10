#include "TreeNode.h"

using namespace aa;

template <typename T>
BiNode<T>* Successor(BiNode<T>* n) {
	if (n == nullptr) {
		return nullptr;
	}

	if (n->right != nullptr) {
		return Minimum(n->right);
	}
	BiNode<T>* y = n->p;
	BiNode<T>* x = n;

	while (y != nullptr && x == y->right) {
		x = y;
		y = y->p;
	}

	return 
}