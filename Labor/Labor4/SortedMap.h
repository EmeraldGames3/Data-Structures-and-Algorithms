#pragma once
//DO NOT INCLUDE SORTEDMAPITERATOR

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;

#include <utility>

typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TPAIR pair<TKey, TValue>(-111111, -111111);

class SMIterator;

typedef bool(*Relation)(TKey, TKey);

struct Node {
    TKey key;
    TValue value;

    //Hashtable SLL
    Node *nextCollision;

    //DLL
    Node *next;
    Node *previous;

    explicit Node(TElem elem) : key(elem.first), value(elem.second), nextCollision(nullptr), next(nullptr),
                                previous(nullptr) {}
};

class SortedMap {
    friend class SMIterator;

public:
    Node **table;

    Node *head;
    Node *tail;

    int capacity;
    int nrElements;
    Relation relation;

    //Hashing function
    static int hash(TKey key, int n);

    //Resize the table to a new capacity
    void resize(int newCapacity);

    //Resize the table to a new capacity automatically
    void automaticResize();

    //Check if a number is prime
    static bool isPrime(int number);

    //Find the first prime number larger than the capacity
    static void findFirstPrime(int number);

public:
    // implicit constructor
    explicit SortedMap(Relation r);

    // adds a pair (key,value) to the map
    //if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
    //if the key SMes not exist, a new pair is added and the value null is returned
    TValue add(TKey c, TValue v);

    //searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise
    [[nodiscard]] TValue search(TKey c) const;

    //removes a key from the map and returns the value associated with the key if the key existed ot null: NULL_TVALUE otherwise
    TValue remove(TKey c);

    //returns the number of pairs (key,value) from the map
    [[nodiscard]] int size() const;

    //checks whether the map is empty or not
    [[nodiscard]] bool isEmpty() const;

    // return the iterator for the map
    // the iterator will return the keys following the order given by the relation
    [[nodiscard]] SMIterator iterator() const;

    // destructor
    ~SortedMap();
};
