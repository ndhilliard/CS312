#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <string>
#include <sstream>

namespace aa 
{
	template <class T>
	class BiNode 
	{
		public:
		T data;
		BiNode<T>* p;
		BiNode<T>* left;
		BiNode<T>* right;
		BiNode() : BiNode(T()) {}
	        BiNode(const T& obj) 
		{
			data = obj;
			p = nullptr;
			left = nullptr;
			right = nullptr;
		}	
	};

	template <typename T>
	void DelTree(BiNode<T>*& obj)
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
