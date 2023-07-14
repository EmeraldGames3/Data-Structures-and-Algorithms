#pragma once

#define NULL_TKEY (-11111)

typedef int TKey;
typedef int(*HashFunction)(TKey, int);

class CoalescedChainingIterator;

class CoalescedChaining {
    friend class CoalescedChainingIterator;
private:
    TKey *table;
    int *next;
    int size;
    int capacity;
    int firstEmpty;
    HashFunction hash;

    static inline int hashDivisionsMethode(TKey key, int capacity) {
        return key % capacity;
    }

    void changeFirstEmpty();

public:
    CoalescedChaining();

    ~CoalescedChaining();

    void add(TKey key);

    void remove(TKey key);

    bool search(TKey key);

    void printTable();

    CoalescedChainingIterator getIterator();
};