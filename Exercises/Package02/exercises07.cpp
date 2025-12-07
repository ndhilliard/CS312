#include "Containers.h"

using namespace aa;
using namespace std;

template <class T>
void Push(Array<T>& A, const T& element) {
	int top = A.first();

	if (top >= (int)A.capacity()) {
		cout << "Error: Stack is full!" << endl;
		return;
	}

	A[top] element;
	A.first() = top + 1;
}

template <class T> 
T Dequeue(Array<T>& A) {
	int& front = A.first();
	int& rear = A.second();

	if (front == rear) {
		throw runtime_error("Error: Queue is empty!");
	}

	T Value = A[front];
	front = (front + 1) % A.capacity();

	return value;
}

template <class T>
void RemoveFirst(Node<T>& head) {
	if (head == nullptr) {
		return;
	}

	Node<T>* temp = head;
	head = head->first();

	if (head != nullptr) {
		head->second() = nullptr;
	}

	delete temp;
}

template <class T>
bool Contains(Node<T> head, const T& target) {
	Node<T>* current = head;

	while (current != nullptr) {
		if (current->data() == target) {
			return true;
		}
		current = current->first();
	}
	return false;
}

template <class T>
int Degree(Node<T>* root) {
	if (root == nullptr) {
		return -1;
	}

	int count = 0;
	Node<T>* child = root->second();

	while (child != nullptr) {
		count++;
		child = child->third();
	}

	return count;
}