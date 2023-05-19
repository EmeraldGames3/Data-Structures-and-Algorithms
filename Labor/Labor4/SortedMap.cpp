#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <cmath>

using namespace std;

/**
* @brief Sorted Map constructor
* @complexity θ(1)
**/
SortedMap::SortedMap(Relation r) {
    relation = r;
    capacity = 13;
    table = new Node *[capacity];
    nrElements = 0;

    for (int i = 0; i < 13; i++) {
        table[i] = nullptr;
    }

    head = nullptr;
    tail = nullptr;
}

/**
* @brief Add an element in the Sorted Map
* @complexityΩ θ(1)
* @complexityθ θ(n)
* @complexityO θ(n)
**/
TValue SortedMap::add(TKey k, TValue v) {
    automaticResize();

    Node *newNode = new Node{TElem{k, v}};
    int position = hash(k, capacity);

    TValue oldValue = NULL_TVALUE;

    //Add the element in the table
    if (table[position] == nullptr) {
        table[position] = newNode;
    } else {
        Node *current = table[position];

        while (current != nullptr) {
            if (current->key == k) {
                oldValue = current->value;
                current->value = v;
                return oldValue;
            }

            current = current->nextCollision;
        }

        newNode->nextCollision = table[position];
        table[position] = newNode;
    }

    //Add the element in the linked list
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        Node *currentNode = head;

        while (currentNode != nullptr && relation(currentNode->key, k)) {
            currentNode = currentNode->next;
        }

        if (currentNode == head) {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
            head->previous = nullptr;
        } else if (currentNode == nullptr) {
            // we add the element onto the end of the list
            newNode->previous = tail;
            tail->next = newNode;
            tail = newNode;
            tail->next = nullptr;
        } else {
            Node *previousNode = currentNode->previous;

            previousNode->next = newNode;
            newNode->previous = previousNode;
            newNode->next = currentNode;
            currentNode->previous = newNode;
        }
    }

    nrElements++; // Increment nrElements after adding a new node
    return oldValue;
}

/**
* @brief search for a key in the Sorted Map
* @complexityΩ θ(1)
* @complexityθ θ(1)
* @complexityO θ(n)
**/
TValue SortedMap::search(TKey k) const {
    if (isEmpty())
        return NULL_TVALUE;

    int position = hash(k, capacity);
    Node *current = table[position];

    while (current != nullptr) {
        if (current->key == k) {
            return current->value;
        }

        current = current->nextCollision;
    }

    return NULL_TVALUE;
}

/**
* @brief Add an element in the Sorted Map
* @complexityΩ θ(1)
* @complexityθ θ(1)
* @complexityO θ(n)
**/
TValue SortedMap::remove(TKey k) {
    if (isEmpty())
        return NULL_TVALUE;

    automaticResize();

    int position = hash(k, capacity);

    if (table[position] == nullptr) {
        //Node is not in the map
        return NULL_TVALUE;
    }

    Node *current = table[position];
    Node *previousCollision = nullptr;
    Node *nodeToBeRemoved;

    while (current != nullptr && current->key != k) {
        previousCollision = current;
        current = current->nextCollision;
    }

    nodeToBeRemoved = current;

    if (current == nullptr) {
        //Node is not in the map
        return NULL_TVALUE;
    }

    if (nrElements == 1) {
        head = nullptr;
        tail = nullptr;
        nrElements = 0;
        TValue value = current->value;
        table[position] = nullptr;
        delete nodeToBeRemoved;
        return value;
    }

    //Remove the node from the collisions list
    if (previousCollision == nullptr) {
        table[position] = nodeToBeRemoved->next;
    } else {
        previousCollision->nextCollision = nodeToBeRemoved->next;
    }

    //Remove the node from the linked list
    if (nodeToBeRemoved == head) {
        if (nodeToBeRemoved == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->previous = nullptr;
        }
    } else if (nodeToBeRemoved == tail) {
        tail = tail->previous;
        tail->next = nullptr;
    } else {
        Node *previous = nodeToBeRemoved->previous;
        Node *next = nodeToBeRemoved->next;

        previous->next = next;
        next->previous = previous;
    }

    nrElements--;
    TValue value = nodeToBeRemoved->value;
    delete nodeToBeRemoved;
    return value;
}

/**
* @brief Find the size of the Sorted Map
* @complexity θ(1)
**/
int SortedMap::size() const {
    return nrElements;
}

/**
* @brief Check if the Sorted Map is empty
* @complexity θ(1)
**/
bool SortedMap::isEmpty() const {
    return nrElements == 0;
}

/**
* @brief Create an iterator for the Sorted Map
* @complexity θ(1)
**/
SMIterator SortedMap::iterator() const {
    return SMIterator(*this);
}

/**
* @brief Sorted map destructor
* @complexity θ(n)
**/
SortedMap::~SortedMap() {
    Node *current = head;
    Node *previous;
    while (current != nullptr) {
        previous = current;
        current = current->next;
        delete previous;
    }
    delete[] table;

    head = nullptr;
    tail = nullptr;
    nrElements = 0;
}

/**
* @brief Find the hash of a key, based on the capacity of the table
* @complexity θ(1)
**/
int SortedMap::hash(TKey key, int n) {
    if (key >= 0)
        return key % n;
    else
        return (n - abs(key) % n) % n;
}

/**
* @brief Check if a number is prime
* @complexity θ(n)
**/
bool SortedMap::isPrime(int number) {
    if (number <= 1) {
        // Numbers less than or equal to 1 are not prime
        return false;
    }

    if (number <= 3) {
        // Numbers 2 and 3 are prime
        return true;
    }

    if (number % 2 == 0 || number % 3 == 0) {
        // Numbers divisible by 2 or 3 are not prime
        return false;
    }

    int i = 5;
    int increment = 2;

    while (i * i <= number) {
        if (number % i == 0) {
            // Number is divisible by i, hence not prime
            return false;
        }

        i += increment;
        increment = 6 - increment;
        // Increment i by 2 or 4 alternately (2, 4, 2, 4, ...)
        // to check for divisibility with numbers other than multiples of 2 and 3
    }

    // If no factors are found, the number is prime
    return true;
}

/**
* @brief Find the first prime number greater than the received number
* @complexity θ(n)
**/
void SortedMap::findFirstPrime(int number) {
    if (number % 2 == 0) {
        // If the number is even, increment it by 1
        // to start searching for the next prime number
        number++;
    }

    while (!isPrime(number)) {
        // Increment the number by 2 (odd numbers only) until a prime is found
        number += 2;
    }
}

/**
* @brief Resize the table to a new capacity
* @complexity θ(n) (θ(n + m), where n is the new capacity and m is the number of elements in the linked list))
**/
void SortedMap::resize(int newCapacity) {
    Node **newTable = new Node *[newCapacity];

    // Initialize the new table with nullptr
    for (int i = 0; i < newCapacity; i++) {
        newTable[i] = nullptr;
    }

    // Rehash all the existing elements into the new table
    Node *currentNode = head;
    while (currentNode != nullptr) {
        int newPosition = hash(currentNode->key, newCapacity);

        // Insert the node at the beginning of the linked list
        currentNode->nextCollision = newTable[newPosition];
        newTable[newPosition] = currentNode;

        currentNode = currentNode->next;
    }

    // Delete the old table and update with the new one
    delete[] table;
    table = newTable;
    capacity = newCapacity;
}

/**
* @complexityΩ θ(1)
* @complexityθ θ(1) // Costuri amortizate
* @complexityO θ(n) (( θ(n + m), where n is the new capacity and m is the number of elements in the linked list) ))
**/
void SortedMap::automaticResize() {
    if (nrElements == capacity) {
        int newCapacity = capacity * 2;
        findFirstPrime(newCapacity);
        resize(newCapacity);
    }
    if (nrElements == capacity / 4 && capacity > 13) {
        int newCapacity = capacity / 2;
        findFirstPrime(newCapacity);
        resize(newCapacity);
    }
}

/**
 * Un map nou cu cheile intr-un interval dat
 * complexity Theta(N)
 */
SortedMap SortedMap::keysInInterval(TKey left, TKey right) const {
    //description: Return a new map with all keys in the given interval
    //pre: S is a sorted map, left is a key and right is key
    //post newMap is a sorted map, where only the keys in the given interval [left, right] remain
    //     newMap = S intersected with [left, right]

    /*
     * newMap = this
     *
     * while(currentNode != NULL)
     *      if(relation(currentNode.key, left) or not relation(currentNode.key, right))
     *         table[position] = table[position].nextCollision
     *
     *      if(currentNode == newMap.head)
     *         newMap.head = currentNode.next
     *         (newMap.head).previous = NULL
     *      else if( currentNode == newMap.tail)
     *         (newMap.tail) = currentNode.previous;
     *         (newMap.tail).next = nullptr;
     *      else
     *         (currentNode.previous).next = currentNode.next;
     *         (currentNode.next).previous = currentNode.previous;
     *
     *      Node *deletedNode = currentNode;
     *      currentNode = currentNode.next;
     *
     *      delete deletedNode;
     *      newMap.nrElements--;
     *
     *      currentNode = currentNode.next
     *
     */

    SortedMap newMap(*this);

    Node *currentNode = newMap.head;
    while (currentNode != nullptr) {
        if( (relation(currentNode->key, left) && currentNode->key != left)|| !relation(currentNode->key, right)){
            int position = hash(currentNode->key, capacity);

            //Delete the node from the table
            table[position] = table[position]->nextCollision;

            //Delete the node from the linked list
            if (currentNode == newMap.head) {
                newMap.head = currentNode->next;
                newMap.head->previous = nullptr;
            } else if (currentNode == newMap.tail) {
                newMap.tail = currentNode->previous;
                newMap.tail->next = nullptr;
            } else {
                (currentNode->previous)->next = currentNode->next;
                (currentNode->next)->previous = currentNode->previous;
            }
            Node *deletedNode = currentNode;
            currentNode = currentNode->next;

            delete deletedNode;
            newMap.nrElements--;
            newMap.automaticResize();
        } else {
            currentNode = currentNode->next;
        }
    }
    return newMap;
}

//@complexity Theta(N)
SortedMap::SortedMap(const SortedMap &other) {
    //description: Copy constructor for SortedMultimap
    //pre: other is a Map
    //post: S' is a new Sorted Map with the same elements as other ( S' = other)

    /*
     * capacity = other.capacity
     * head = other.head
     * Node *current = other.head
     * nrElems = other.nrElems
     *
     * while( current != NULL)
     *      newNode = current
     *      position = hash(newNode.key, capacity)
     *
     *      if(table[position] == NULL)
     *          table[position] = newNode
     *      else
     *          newNode.nextCollision = table[position]
     *          table[position] = newNode
     *
     *      newNode.previous = currentThis;
     *      currentThis.next = newNode
     *
     *      currentOther = currentOther.next
     *      currentThis = currentThis.next
     */

    capacity = other.capacity;
    table = new Node *[capacity];
    nrElements = other.nrElements;
    relation = other.relation;

    Node *newNode = new Node{TElem{other.head->key, other.head->value}};
    head = newNode;
    table[hash(newNode->key, capacity)] = newNode;
    tail = head;

    Node *currentOther = other.head->next;
    Node *currentThis = head;

    while (currentOther != nullptr) {
        newNode = new Node{TElem{currentOther->key, currentOther->value}};

        int position = hash(newNode->key, capacity);

        //Add the element in the table
        if (table[position] == nullptr) {
            table[position] = newNode;
        } else {
            newNode->nextCollision = table[position];
            table[position] = newNode;
        }

        //Add the element in the linked list
        newNode->previous = currentThis;
        currentThis->next = newNode;

        currentOther = currentOther->next;
        currentThis = currentThis->next;
    }
}
