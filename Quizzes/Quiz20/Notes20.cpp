#include "TreeNode.h"

using namespace aa;

template <typename T>
void Transplant(BiNode<T>*& root, BiNode<T>* x, BiNode<T>* y) {
	if (x->p == nullptr) {
		root = y;
	} else if (x = x->p->left) {
		x->p->left = y;
	} else {
		x->p->right = y;
	}

	if (y != nullptr) {
		y->p = x->p;
	}
}