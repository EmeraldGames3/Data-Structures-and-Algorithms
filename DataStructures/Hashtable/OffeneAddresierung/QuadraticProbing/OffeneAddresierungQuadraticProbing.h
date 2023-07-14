#pragma once

#define NULL_TKEY (-11111)

typedef int TKey;
typedef int(*HashFunction)(TKey, int);

class OffeneAddressierungQuadraticProbingIterator;

class OffeneAddressierungQuadraticProbing {
    friend class OffeneAddressierungQuadraticProbingIterator;

private:
    int capacity;
    int size;
    TKey *table;
    HashFunction hash;

    static inline int hashDivisionsMethode(TKey key, int capacity) {
        return key % capacity;
    }

public:
    OffeneAddressierungQuadraticProbing();

    ~OffeneAddressierungQuadraticProbing();

    void add(TKey key);

    void remove(TKey key);

    bool search(TKey key);

    void printTable();

    OffeneAddressierungQuadraticProbingIterator getIterator();
};