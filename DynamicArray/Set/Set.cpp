#include "Set.h"
#include "SetITerator.h"

Set::Set() {
    //TODO - Implementation
    set = new TElem[20];
    max_size = 20;
    current_size = 0;

}


bool Set::add(TElem elem) {
    //TODO - Implementation
    if (search(elem))
        return false;
    set[current_size] = elem;
    current_size++;
    return true;

}


bool Set::remove(TElem elem) {
    //TODO - Implementation
    int position = -1;
    for (int index = 0; index < current_size; index++)
        if (elem == set[index])
            position = index;
    if (position == -1)
        return false;
    for (int index = position; index < current_size; index++)
        set[index] = set[index+1];
    current_size--;
    return true;
}

bool Set::search(TElem elem) const {
    //TODO - Implementation
    for (int index = 0; index < current_size; index++)
        if (set[index] == elem)
            return true;
    return false;
}


int Set::size() const {
    //TODO - Implementation
    return current_size;
}


bool Set::isEmpty() const {
    //TODO - Implementation
    if(current_size == 0)
        return true;
    return false;
}

Set::~Set() {
    //TODO - Implementation
    delete[] set;
}


SetIterator Set::iterator() const {
    return SetIterator(*this);
}


