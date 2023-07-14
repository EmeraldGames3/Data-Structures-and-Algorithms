#pragma once

#define NULL_TKEY (-11111)

typedef int TKey;
typedef int(*HashFunction)(TKey, int);

class OffeneAddressierungDoubleHashingIterator;

class OffeneAddressierungDoubleHashing {
    friend class OffeneAddressierungDoubleHashingIterator;

private:
    int capacity;
    int size;
    TKey *table;
    HashFunction hash1;
    HashFunction hash2;

    static inline int hashF1(TKey key, int capacity) {
        return key % capacity;
    }

    static inline int hashF2(TKey key, int capacity) {
        const int prime = 31;
        return prime - (key % prime);
    }

public:
    OffeneAddressierungDoubleHashing();

    ~OffeneAddressierungDoubleHashing();

    void add(TKey key);

    void remove(TKey key);

    bool search(TKey key);

    void printTable();
};