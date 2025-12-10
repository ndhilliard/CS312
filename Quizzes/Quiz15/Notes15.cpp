#include "TreeNode.h"

using namespace aa;

template <typename T>
BiNode<T> Minimum(BiNode<T>* root) {
	if (root == nullptr) {
		return nullptr;
	}

	BiNode<T>* i = root;

	while (i->left != nullptr) {
		i = i->left;
	}

	return i;
}