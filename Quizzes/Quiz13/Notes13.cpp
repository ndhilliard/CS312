#include "TreeNode.h"

using namespace aa;

template <typename T>
void PostOrder(BiNode<T>* root) {

	if (root != nullptr) {
		PostOrder(root->left);
		PostOrder(root->right);
		std::cout << root->data << " ";
	}
}