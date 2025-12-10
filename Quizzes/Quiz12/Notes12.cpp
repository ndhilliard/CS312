#include "TreeNode.h"

using namespace aa;

template <typename T>
void PreOrder(BiNode<T>* root) {
	if (root != nullptr) {
		std::cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}


