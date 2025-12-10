#include "TreeNode.h"

using namespace aa;

template <typename T>
void Insert(BiNode<T>* item, const T& key) {
	BiNode<T>* i = new BiNode<T>(key);
	if (item == nullptr) {
		item = i;
	} else {
		BiNode<T>* t = item;
		BiNode<T>* p = nullptr;

		while (t != nullptr) {
			p = t;
			if (t->data > key) {
				t = t->left;
			} else {
				t = t->right;
			}
		}

		if (p->data > key) {
			p->left = i;
		} else {
			p->right = i;
		}
	}
}