#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cctype>
#include "Object.h"
#include "BiTree.h"

namespace aap
{
    class Pair : public Object
    {
        private:
        char ch;
        int freq;

        public:
        Pair() : ch('\0'), freq(0) {}
        Pair(char k,int v) : ch(k), freq(v) {}
        Pair(const Pair& obj) {*this = obj;}
        virtual ~Pair() {}
        
        Pair& operator=(const Pair& rhs)
        {
            if(this != &rhs)
            {
                ch = rhs.ch;
                freq = rhs.freq;
            }
            return *this;
        }

        char& key() {return ch;}
        const char& key() const {return ch;}
        int& value() {return freq;}
        const int& value() const {return freq;}
        
        std::string toString() const override 
        {
            std::stringstream out;
            out << ch << ":" << freq;
            return out.str();
        }
    };

    class PairTree : public Object 
    {
        private:
        BiTree<Pair> *node;

        void inorder(BiTree<Pair>* rt,std::stringstream& out) const
        {
            if(rt != nullptr)
            {
                inorder(rt->left,out);
                out << rt->data << " ";
                inorder(rt->right,out);
            }
        }

        public: 
        PairTree() : node(nullptr) {}
        PairTree(const Pair& obj) 
        {
            node = new BiTree<Pair>(obj);
        }
        PairTree(const PairTree& obj) : PairTree() {*this = obj;}

        PairTree& operator=(const PairTree& rhs)
        {
            if(this != &rhs)
            {
                node = CopyTree(rhs.node);
            }
            return *this;
        }

        virtual ~PairTree() 
        {
            DelTree(node);
        }

        void addLeft(PairTree& obj)
        {
            if(node == nullptr) {node = CopyTree(obj.node);}
            BiTree<Pair>* n = node;
            while(n->left != nullptr) {n = n->left;}
            n->left = CopyTree(obj.node);
        }
        
        void addRight(PairTree& obj)
        {
            if(node == nullptr) {node = CopyTree(obj.node);}
            BiTree<Pair>* n = node;
            while(n->right != nullptr) {n = n->right;}
            n->right = CopyTree(obj.node);
        }

        std::string toString() const override 
        {
            std::stringstream out;
            inorder(node,out);
            return out.str();
        }
    };

    class PairArray : public Object 
    {
        private:
        Pair data[100];
        size_t size;

        public:
        PairArray() : size(0) {}
        PairArray(const PairArray& obj) {*this = obj;}

        PairArray& operator=(const PairArray& rhs)
        {
            if(this != &rhs)
            {
                size = rhs.size;

                for(size_t i = 0;i < size;i += 1)
                {
                    data[i] = rhs.data[i];
                }
            }
            return *this;
        }
        
        virtual ~PairArray() {}

        Pair& operator[](size_t i)
        {
            if(i < 100) {return data[i];}
            throw std::out_of_range("out of bound");
        }

        const Pair& operator[](size_t i) const
        {
            if(i < 100) {return data[i];}
            throw std::out_of_range("out of bound");
        }

        size_t length() const {return size;}

        void set(size_t v) 
        {
            if(v < 100) {size = v;}
        }
        
        void add(const Pair& obj) 
        {
            if(size < 100)
            {
                data[size] = obj;
                size += 1;
            }
        }

        void remove() 
        {
            if(size < 0){size -= 1;}
        }

        size_t index(char ch) const 
        {
            size_t i = 0;
            
            while(i < size && data[i].key() != ch) {i += 1;}
            return i;
        }

        std::string toString() const override 
        {
            std::stringstream out;

            for(size_t i = 0;i < size;i += 1)
            {
                out << "[" << data[i] << "]";
            }
            return out.str();
        }
    };

    bool Ignore(char ch)
    {
        return isspace(ch) || ch == '\0';
    }

    PairArray frequency(std::string filename)
    {
        std::fstream fread(filename.data(),std::fstream::in);
        PairArray A;

        if(fread.is_open())
        {
            char ch;

            while(fread >> ch)
            {
                ch = tolower(ch);
                size_t i;

                if(!Ignore(ch))
                {
                    i = A.index(ch);
                    if(i == A.length()) 
                    {
                        A.add(Pair(ch,1));
                    }  
                    else 
                    {
                        A[i].value() += 1;
                    }
                }
            }
        }
        fread.close();
        return A;
    }
}

#endif