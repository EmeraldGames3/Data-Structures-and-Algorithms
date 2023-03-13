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
//	system("pause"); It doesn't work for some reason TODO: Find out why and fix it
}
