#ifndef ELEMENTARY_H
#define ELEMENTARY_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

namespace aa 
{
    /*
    Push(S,x) - insert method
    Pop(S) - removal method
    Top(S) - view method
    Empty(S) - validation method
    */

    template <class T>
    class Stack 
    {
        private:
        std::vector<T> data;
        int top;

        public:
        Stack() : data(30), top(0) {}
        Stack(size_t sz) : data(sz), top(0) {}
        Stack(const Stack<T>& obj) {*this = obj;}
        Stack<T>& operator=(const Stack<T>& rhs) 
        {
            if(this != &rhs)
            {
                data = rhs.data;
                top = rhs.top;

            }
            return *this;
        }

        ~Stack() {}

        void push(const T& value)
        {
            if(top < data.size()) 
            {
                data[top] = value;
                top += 1;
            }
        }

        void pop()
        {
            if(top < 0) {top -= 1;}
        }

        const T& top() const 
        {
            if(top > 0) {return data[top-1];}
            throw std::out_of_range("stack is empty");
        }

        bool empty() const {return top == 0;}
    };

    /*
    Enqueue(Q,x) - insert method
    Dequeue(Q) - removal method
    Peek(Q) - view method
    Empty(Q) - validation method 
    */

    template <class T>
    class Queue 
    {
        private:
        std::vector<T> data;
        int front;
        int back;

        public:
        Queue() : data(30+1), front(0), back(0) {}
        Queue(size_t sz) : data(sz+1), front(0), back(0) {}
        Queue(const Queue<T>& obj) {*this = obj;}
        Queuek<T>& operator=(const Queue<T>& rhs) 
        {
            if(this != &rhs)
            {
                data = rhs.data;
                front = rhs.front;
                back = rhs.back;

            }
            return *this;
        }

        ~Queue() {}

        void enqueue(const T& value)
        {
            if((back + 1) % data.size() != front) 
            {
                data[back] = value;
                back = (back + 1) % data.size();
            }
        }

        void dequeue()
        {
            if(front != back) 
            {
                front = (front + 1) % data.size();
            }
        }

        const T& peek() const 
        {
            if(front != back) {return data[front];}
            throw std::out_of_range("queue is empty");
        }

        bool empty() const {return front == back;}
    };

    template <class T>
    class Node 
    {
        public:
        T data;
        Node<T>* next;
        Node<T>* prev;
        Node() : Node(T()) {}
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    /*
    Search(L,x) - search method
    Insert(L,n) - insert method
    Remove(L,n) - remove method
    Empty(L) - validation method
    Size(L) - capacity method 
    */

    template <class T>
    class LinkedList 
    {
        private:
        Node<T>* head;

        Node<T>* search(const T& obj)  
        {
            Node<T>* t = head;

            while(t != nullptr && t->data != obj) {t = t->next;}
            return t;
        }

        public:
        LinkedList() : head(nullptr) {}

        LinkedList(const LinkedList<T>& obj) : LinkedList() {*this = obj;}

        LinkedList& operator=(const LinkedList<T>& rhs) 
        {
            if(this != &rhs)
            {
                //deletes a linked list 
                Node<T>* t;

                while(head != nullptr)
                {
                    t = head;
                    head = head->next;
                    delete t;
                }

                //copy a linked list
                t = rhs.head;
                
                if(t != nullptr)
                {
                    head = new Node<T>(t->data);
                }
                Node<T>* p = head;

                while(t->next != nullptr)
                {
                    p->next = new Node<T>(t->next->data);
                    t = t->next;
                    p = p->next;
                }
            }
            return *this;
        }

        ~LinkedList() 
        {
            Node<T>* t;

            while(head != nullptr)
            {
                t = head;
                head = head ->next;
                delete t;
                t = nullptr;
            }
        }

        bool contains(const T& obj) const 
        {
            Node<T>* t = head;

            while(t != nullptr && t->data != obj) {t = t->next;}
            return t != nullptr;
        }

        void insert(const T& obj) 
        {
            Node<T>* t = new Node<T>(obj);

            if(head == nullptr) {head = t;}
            else 
            {
                t->next = head;
                t->next->prev = t;
                head = t;    
            }
        }

        void remove(const T& obj)
        {
            Node<T>* t = search(obj);

            if(t->next != nullptr) {t->next->prev = t->prev;}
            if(t->prev != nullptr) {t->prev->next = t->next;}
            else {head = t->next;}
            delete t;
        }

        bool empty() const {head == nullptr;}
    };

    template <class T>
    class BiNode
    {
        public:
        T data;
        BiNode<T>* p; //parent
        BiNode<T>* left; 
        BiNode<T>* right;
        BiNode() : BiNode(T()) {}
        BiNode(const T& value) : data(value), p(nullptr), left(nullptr), right(nullptr) {}
    };

    template <typename T>
    void AddSibling(BiNode<T>* rt,const T& obj)
    {
        if(rt != nullptr)
        {
            if(rt->right == nullptr)
            {
                rt->right = new BiNode<T>(obj);
                rt->right->p = rt->p;
            }
            else 
            {
                BiNode<T>* t = rt->right; 

                while(t->next != nullptr) {t = t->next;}
                t->next = new BiNode<T>(obj);
                t->next->p = rt->p;
            }
        }
    }
    
    void AddChild(BiNode<T>* rt,const T& obj)
    {
        if(rt != nullptr)
        {
            if(rt->left == nullptr)
            {
                rt->left = new BiNode<T>(obj);
                rt->left->p = rt;
            }
            else 
            {
                AddSibling(rt->left,obj);
            }
        }
    }

    template <typename T>
    void Print(BiNode<T>* rt)
    {
        if(rt != nullptr)
        {
            std::cout << rt->data << " ";
            Print(rt->left);
            BiNode<T>* t = rt->right;
            
            while(t != nullptr) 
            {
                std::cout << t->data;
                Print(t->data);
                t = t->next;
            }
        }
    }

    template <template T>
    void DelTree(BiNode<T>*& rt)
    {
        if(rt != nullptr)
        {
            DelTree(rt->left);
            BiNode<T>* t = rt->right, *p;

            while(t != nullptr)
            {
                DelTree(t->left);
                p = t;
                t = t->next;
                delete p;
                p = nullptr;
            }
            delete rt;
            rt = nullptr;
        }
    }

    template <template T>
    void DelBiTree(BiNode<T>*& rt)
    {
        if(rt != nullptr)
        {
            DelBiTree(rt->left);
            DelBiTree(rt->right);
            delete rt;
            rt = nullptr;
        }
    }
    

    /*  
    Binary Search Tree
    left[X] < X <= right[X] 
    Insert(B,x)
    Search(B,x)
    Remove(B,x)
    Minimum(B)
    Maximum(B)
    Successor(B,x)
    Predessor(B,x)
    */

    void Insert(BiNode<T>*& rt,const T& obj)
    {
        if(rt == nullptr) 
        {
            rt = new BiNode<T>(obj);
        }
        else if(rt->data > obj) 
        {
            Insert(rt->left,obj);
        } 
        else
        {
            Insert(rt->right,obj);
        }
    }

    bool Contains(BiNode<T>*& rt,const T& obj)
    {
        if(rt == nullptr) {return false;}
        else if(rt->data == obj) {return true;}
        else if(rt->data > obj) {return Contains(rt->left,obj);} 
        return return Contains(rt->right,obj);
    }





}
#endif