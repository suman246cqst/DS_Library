#ifndef HASHMAP_H
#define HASHMAP_H

#include "dynamicArray.h"
#include "linkedList.h"

template<typename K, typename V>
class HashNode{
public:
    K key;
    V value;
    HashNode();
    HashNode(const K& key, const V& value);
    HashNode(const HashNode<K,V>& other);
    ~HashNode();
};

template<typename K, typename V>
class HashMap{
private:
    DynamicArray<LinkedList<HashNode<K,V>>*> bucketArray;
    int size;
    int capacity;
    float loadfactor;
    float threshold;
public:
    HashMap();
    ~HashMap();
    HashMap(const HashMap<K,V>& other);
    HashMap<K,V>& operator=(const HashMap<K,V>& other);
};

#include "hashMap.cpp"

#endif