#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include "BiTree.h"
#include "Pair.h"

class Heap {

private: 
	aap::BiTree<Pair>** A;
	int size;
	int capacity;

	void resize() {
		int newCap = capacity * 2;
		aap::BiTree<Pair>** temp = new aap::BiTree<Pair>*[newCap];

		for (int i = 0; i < size; i++) {
			temp[i] = A[i];
		}

		delete[] A;
		A = temp;
		capacity = newCap;
	}

	void heapifyUp(int index) {
		while (index > 0) {
			int parent = (index - 1) / 2;

			if (A[index]->data.getValue() < A[parent]->data.getValue()) {
				aap::BiTree<Pair>* temp = A[index];
				A[index] = A[parent];
				A[parent] = temp;
				index = parent;
			} else {
				break;
			}
		}
	}

	void heapifyDown(int index) {
		while (true) {
			int left = index * 2 + 1;
			int right = index * 2 + 2;
			int smallest = index;

			if (left < size && A[left]->data.getValue() < A[smallest]->data.getValue()) {
				smallest = left;
			}
			if (right < size && A[right]->data.getValue() < A[smallest]->data.getValue()) {
				smallest = right;
			} 
			if (smallest != index) {
				aap::BiTree<Pair>* temp = A[index];
				A[index] = A[smallest];
				A[smallest] = temp;
				index = smallest;
			} else {
				break;
			}
		}
	}

public:

	Heap() : size(0), capacity(10) {
		A = new aap::BiTree<Pair>*[capacity];
	}

	~Heap() {
		delete[] A;
		A = nullptr;
	}

	void push(aap::BiTree<Pair>* node) {
		if (size == capacity) {
			resize();
		}

		A[size] = node;
		heapifyUp(size);
		size++;
	}

	aap::BiTree<Pair>* pop() {
		if (size == 0) {
			return nullptr;
		}

		aap::BiTree<Pair>* root = A[0];

		A[0] = A[size - 1];
		size--;

		heapifyDown(0);
		return root;
	}

	bool isEmpty() const {
		return size == 0;
	}
	int getSize() const {
		return size;
	}

};
#endif // !HEAP_H

