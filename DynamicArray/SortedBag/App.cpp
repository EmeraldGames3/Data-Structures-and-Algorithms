#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "testExtendedIterator.h"

using namespace std;

int main() {
    testAll();
    testAllExtended();
    testExtendedIterator();

    cout << "Test over" << endl;
//	system("pause");
    cin.get();
}
