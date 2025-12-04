#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include <string>
#include <sstream>
#include "Object.h"

class Pair : public aap::Object {

private:
    std::string key;
    int value;

public:
    Pair() : key(""), value(0) {}
    Pair(std::string key, int value) : key(key), value(value) {}
    Pair(const Pair& obj) { *this = obj; }

    Pair& operator=(const Pair& rhs) {
        if (this != &rhs) {
            key = rhs.key;
            value = rhs.value;
        }
        return *this;
    }

    std::string getKey() const { return key; }
    int getValue() const { return value; }

    void setKey(std::string obj) { key = obj; }
    void setValue(int obj) { value = obj; }

    std::string toString() const override {
        std::stringstream out;
        out << "(" << key << "," << value << ")";
        return out.str();
    }
};

#endif