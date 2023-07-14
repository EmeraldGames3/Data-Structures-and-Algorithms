#pragma once

#include "OffeneAddressierungLinearProbing.h"

class OffeneAddressierungLinearProbingIterator {
private:
    friend class OffeneAddressierungLinearProbing;

    const OffeneAddressierungLinearProbing &table;

    int currentPosition;

    explicit OffeneAddressierungLinearProbingIterator(const OffeneAddressierungLinearProbing &t);

public:

    void first();

    void next();

    bool valid();

    TKey getCurrent();
};