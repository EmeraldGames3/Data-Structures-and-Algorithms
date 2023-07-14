#pragma once

#define NULL_TKEY (-11111)

typedef int TKey;
typedef int(*HashFunction)(TKey, int);

class OffeneAddressierungLinearProbingIterator;

class OffeneAddressierungLinearProbing {
    friend class OffeneAddressierungLinearProbingIterator;
private:
    int capacity;
    int size;
    TKey *table;
    HashFunction hashFunction;

    static inline int hashDivisionsMethode(TKey key, int capacity) {
        return key % capacity;
    }

public:
    OffeneAddressierungLinearProbing();

    ~OffeneAddressierungLinearProbing();

    void add(TKey key);

    void remove(TKey key);

    bool search(TKey key);

    void printTable();

    OffeneAddressierungLinearProbingIterator getIterator();
};
