#pragma once

#include "UnabhangigeVekettung.h"

class UnabhangigeVerkettungIterator {
    friend class UnabhangigeVerkettung;

private:

    const UnabhangigeVerkettung &hashTable;
    int currentPosition;
    Node *current;

    explicit UnabhangigeVerkettungIterator(const UnabhangigeVerkettung& t);

public:

    void first();

    void next();

    TElem getCurrent();

    bool valid();
};