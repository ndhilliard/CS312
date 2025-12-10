#include "TreeNode.h"

using namespace aa;

template <typename T>
void InOrder(BiNode<T>* root) {

	if (root != nullptr) {
		InOrder(root->left);
		std::cout << root->data << " ";
		InOrder(root->right);
	}
}

