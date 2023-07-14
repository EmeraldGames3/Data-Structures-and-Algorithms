#pragma once

#include "OffeneAddresierungQuadraticProbing.h"

class OffeneAddressierungQuadraticProbingIterator {
private:

    friend class OffeneAddressierungQuadraticProbing;

    const OffeneAddressierungQuadraticProbing &table;

    int currentPosition;

    explicit OffeneAddressierungQuadraticProbingIterator(const OffeneAddressierungQuadraticProbing &t);

public:

    void first();

    void next();

    bool valid();

    TKey getCurrent();



};