#include "SortedBag/SortedBag.h"
#include "SortedBagIterator/SortedBagIterator.h"
#include <iostream>
#include "Tests/ShortTest.h"
#include "Tests/ExtendedTest.h"

using namespace std;

int main() {
	testAll();
	testAllExtended();
	
	cout << "Test over" << endl;
	system("pause");
}
