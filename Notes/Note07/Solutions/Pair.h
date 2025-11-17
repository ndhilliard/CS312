#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include <string>
#include <sstream>

namespace aa
{
    template <class V>
    class Pair 
    {
        private:
        int _key;
        V _value;

        public:
        Pair() : _key(0), _value(V()) {}
        Pair(int key,const V& value) : _key(key), _value(value) {}
        Pair(const Pair<V>& obj) {*this = obj;}

        Pair<V>& operator=(const Pair<V>& rhs)
        {
            if(this != &rhs)
            {
                _key = rhs._key;
                _value = rhs._value;
            }
            return *this;
        }
        ~Pair() {}

        int& key() {return _key;}
        const int& key() const {return _key;}
        V& value() {return _value;}
        const V& value() const {return _value;}

        std::string toString() const 
        {
            std::stringstream out;
            out << "(" << _key << "," << _value << ")";
            return out.str();
        }

        friend std::ostream& operator<<(std::ostream& out,const Pair<V>& obj)
        {
            out << obj.toString();
            return out;
        }
    };
}
#endif