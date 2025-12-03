#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

namespace aa 
{	
	template <class T>
	class Array 
	{
		private:
		std::vector<T> data;
		int index[2];

		public:
		Array() : Array(20) {}
		
		Array(size_t sz) : index{0,0} 
		{
			if(sz == 0) {sz = 20;}
			data = std::vector<T>(sz);
		}
		
		Array(const Array<T>& obj) {*this = obj;}

		Array<T>& operator=(const Array<T>& rhs) 
		{
			if(this != &rhs)
			{
				data = rhs.data;
				index[0] = rhs.index[0];
				index[1] = rhs.index[1];
			}
			return *this;
		}

		~Array() {}

		int& first() {return index[0];} 
		const int& first() const {return index[0];}
		int& second() {return index[1];}
		const int& second() const {return index[1];}
		size_t capacity() const {return data.size();}

		T& operator[](size_t idx) 
		{
			if(idx < data.size()) {return data[idx];}
			throw std::out_of_range("out of bound");
		}

		const T& operator[](size_t idx) const 
		{
			if(idx < data.size()) {return data[idx];}
			throw std::out_of_range("out of bound");
		}
	};

	template <class T>
	class Node 
	{
		private:
		T value;
		Node<T> *links[3];
		Node(const Node<T>&) = delete;
		Node<T> operator=(const Node<T>&) = delete;

		public:
		Node() : Node(T()) {}
		Node(const T& obj) : value(obj), links{nullptr,nullptr,nullptr} {}	
		~Node() {}
		const T& data() const {return value;}
		T& data() {return value;}
		Node<T>*& first() {return links[0];}
		const Node<T>*& first() const {return links[0];}
		Node<T>*& second() {return links[1];}
		const Node<T>*& second() const {return links[1];}
		Node<T>*& third() {return links[2];}
		const Node<T>*& third() const {return links[2];}
	};	
}
#endif
