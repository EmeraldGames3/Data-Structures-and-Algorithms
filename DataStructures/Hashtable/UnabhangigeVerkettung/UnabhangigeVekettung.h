#pragma once

#include <utility>
#include <iostream>
#include <vector>

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

typedef int(*HashFunction)(TKey, int);

#define NULL_TVALUE (-111111);
#define NULL_TKEY (-111111);
#define NULL_TELEM std::pair<TKey, TValue>(NULL_TKEY, NULL_TVALUE);

class UnabhangigeVerkettungIterator;

struct Node {
    TElem element;
    Node *next;
};

class UnabhangigeVerkettung {
    friend class UnabhangigeVerkettungIterator;

private:
    Node **table;
    int capacity;
    int size;
    HashFunction hash;
    constexpr static const double LOAD_FACTOR_THRESHOLD = 1;
    constexpr static const int MAX_REHASHES = 10;

    void resizeAndRehash(int newCapacity);

    void automaticResizeAndRehash();

public:
    static inline int hashDivisionsMethode(TKey key, int capacity) {
        return key % capacity;
    }

    static inline int hashMultiplikationsMethode(TKey key, int capacity) {
        return capacity * (int((key * 0.5456)) % 1);
    }

    static inline int hashUniversellesMethode(TKey key, int capacity) {
        const int prime1 = 31;
        const int prime2 = 37;
        return ( (prime1 % capacity) * key + prime2 % key) % key;
    }

    explicit UnabhangigeVerkettung(HashFunction h);

    ~UnabhangigeVerkettung();

    void add(TKey key, TValue value);

    TValue remove(TKey key, TValue value);

    bool search(TKey key);

    UnabhangigeVerkettungIterator getIterator();

    void printTable();
};