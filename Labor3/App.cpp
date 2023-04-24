#include "Queue/Queue.h"
#include "Queue/ExtendedTest.h"
#include "Queue/ShortTest.h"
#include "Stack/StackTest/StackTest.h"
#include <iostream>

using namespace std;

int main() {
    testStack();
	testAll();
	testAllExtended();

	cout << "Test end" << endl;
}