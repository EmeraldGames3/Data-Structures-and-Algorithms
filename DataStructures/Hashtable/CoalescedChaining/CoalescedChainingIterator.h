#pragma once
#include "CoalescedChaining.h"

class CoalescedChainingIterator {

    friend class CoalescedChaining;

    const CoalescedChaining &table;

    int currentPosition;

    explicit CoalescedChainingIterator(const CoalescedChaining& t);

public:

    void first();

    void next();
    
    bool valid();

    TKey getCurrent();
};