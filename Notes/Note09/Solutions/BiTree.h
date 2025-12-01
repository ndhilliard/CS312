#ifndef BITREE_H
#define BITREE_H

#include <iostream>
#include <string>

namespace aap
{
	template <class T>
	class BiTree 
	{
		public:
		T data;
		BiTree<T>* left;
		BiTree<T>* right;
		BiTree() : data(T()), left(nullptr), right(nullptr) {}
		BiTree(const T& obj) : data(obj), left(nullptr), right(nullptr) {}
		virtual ~BiTree() {}
	};

	template <typename T>
	void DelTree(BiTree<T>*& obj)
	{
		if(obj != nullptr)
		{
			DelTree(obj->left);
			DelTree(obj->right);
			delete obj;
			obj = nullptr;
		}
	}
}

#endif 
