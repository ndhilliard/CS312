#include "TreeNode.h"

using namespace aa;

template <typename T>
BiNode<T>* Search(BiNode<T>* root, const T& key) {
	if (root == nullptr) {
		return nullptr;
	} else if (root->data == key) {
		return root;
	} else if (root->data > key) {
		return Search(root->left, key);
	} else {
		return Search(root->right, key);
	}
}