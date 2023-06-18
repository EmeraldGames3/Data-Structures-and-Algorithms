#include <iostream>
#include "LinkedListOnArrays/DLLA/DLLA.h"
#include "LinkedListOnArrays/DLLA/DLLAIterator.h"

using std::cout;

int main() {
    DLLA d;
    d.addToStart(4);
    d.addToStart(2);
    d.addToStart(1);
    d.addToStart(0);

    auto iterator = d.getIterator();
    while (iterator.valid()){
        cout << iterator.getCurrent() << ' ';
        iterator.next();
    }

    cout << "\n\n";

    d.removeFromStart();
    d.removeFromStart();

    iterator.first();
    while (iterator.valid()){
        cout << iterator.getCurrent() << ' ';
        iterator.next();
    }
    return 0;
}