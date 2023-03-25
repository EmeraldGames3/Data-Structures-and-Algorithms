#include "LocationTests/LocationTests.h"
#include "LocationQueueTests/LocationQueueTests.h"
#include "QueueTest/ShortTest.h"
#include "QueueTest/ExtendedTest.h"
#include <iostream>

void testAllFunctionalities() {
    //Test queue
    testAll();
    testAllExtended();

    //TestLocation
    testLocation();

    //Test LocationQueue
    testLocationQueue();

    std::cout << "\n";
}