#include "TreeNode.h"

using namespace aa;

template <typename T>
BiNode<T>* Maximum(BiNode<T>* root) {
	if (root == nullptr) {
		return nullptr;
	}

	BiNode<T>* i = root;

	while (i->right != nullptr) {
		i = i->right;
	}

	return i;
}