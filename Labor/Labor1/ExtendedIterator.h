#pragma once
#include "SortedBag.h"

class SortedBag;

class ExtendedSortedBagIterator{
    friend class SortedBag;

private:
    int current;
    const SortedBag &bag;

    ExtendedSortedBagIterator(const SortedBag &b, int position);

public:
    TComp getCurrent();

    bool valid();

    void next();

    void previous();

    void first();
};

