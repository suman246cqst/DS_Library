#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

#include <string>
#include <cstdint>

class HashFunction {
public:
    int generateHash(int key);
    int generateHash(char key);
    int generateHash(bool key);
    int generateHash(const std::string& key);
    int generateHash(float key);
    int generateHash(double key);
    int generateHash(long key);
    int generateHash(short key);
    template<typename T>
    int generateHash(const T& obj);
};
#include "hashFunction.cpp"
#endif