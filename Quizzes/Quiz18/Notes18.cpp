#include "TreeNode.h"

using namespace aa;

template <typename T>
BiNode<T>* predecessor(BiNode<T>* n) {
	if (n == nullptr) {
		return nullptr;
	}

	if (n->left != nullptr) {
		return Maximum(n->left);
	}
	BiNode<T>* y = n->p;
	BiNode<T>* x = n;

	while (y != nullptr && x == y->left) {
		x = y;
		y = y->p;
	}

	return y;
}