#include "hashMap.h"
using namespace std;

template<typename K, typename V>
HashNode<K,V>::HashNode() = default;
template<typename K ,typename V>
HashNode<K,V>::HashNode(const K& key, const V& value){
    this->key=key;
    this->value=value;
}
template<typename K, typename V>
HashNode<K,V>::HashNode(const HashNode<K,V>& other){
    this->key=other.key;
    this->value=other.value;
}
template<typename K, typename V>
HashNode<K,V>::~HashNode(){
    key.~K();
    value.~V();
}
template<typename K, typename V>
HashMap<K,V>::HashMap(){
    size=0;
    capacity=16;
    loadfactor=0.0;
    threshold=0.70;
    for(int i=0;i<16;i++){
        bucketArray.push_back(nullptr);
    }
}
template<typename K, typename V>
HashMap<K,V>::~HashMap(){
    for(int i = 0; i < capacity; i++){
        if(bucketArray[i] != nullptr){
            bucketArray[i]->~LinkedList<HashNode<K,V>>();
            free(bucketArray[i]);
            bucketArray[i]=nullptr;
        }
    }
}
template<typename K, typename V>
HashMap<K,V>& HashMap<K,V>::operator=(const HashMap<K,V>& other){
    if(this == &other){
        return *this;
    }       
    for(int i = 0; i < capacity; i++){
        if(bucketArray[i] != nullptr){
            bucketArray[i]->~LinkedList<HashNode<K,V>>();
            free(bucketArray[i]);
            bucketArray[i]=nullptr;
        }
    }
    bucketArray = DynamicArray<LinkedList<HashNode<K,V>>*>();
    size = other.size;
    capacity = other.capacity;
    loadfactor = other.loadfactor;
    threshold = other.threshold;
    for(int i = 0; i < capacity; i++){
        if(other.bucketArray[i] == nullptr){
            bucketArray.push_back(nullptr);
        }
        else{
            LinkedList<HashNode<K,V>>* list =(LinkedList<HashNode<K,V>>*)malloc(sizeof(LinkedList<HashNode<K,V>>));
            if(list == nullptr){
                throw bad_alloc();
            }    
            new (list) LinkedList<HashNode<K,V>>(*other.bucketArray[i]);
            bucketArray.push_back(list);
        }
    }
    return *this;
}
template<typename K, typename V>
HashMap<K,V>::HashMap(const HashMap<K,V>& other){
    size = other.size;
    capacity = other.capacity;
    loadfactor = other.loadfactor;
    threshold = other.threshold;
    for(int i = 0; i < capacity; i++){
        if(other.bucketArray[i] == nullptr){
            bucketArray.push_back(nullptr);
        }
        else{
            LinkedList<HashNode<K,V>>* list =(LinkedList<HashNode<K,V>>*)malloc(sizeof(LinkedList<HashNode<K,V>>));
            if(list == nullptr){
                throw bad_alloc();
            }
            new (list) LinkedList<HashNode<K,V>>(*other.bucketArray[i]);
            bucketArray.push_back(list);
        }
    }
}
