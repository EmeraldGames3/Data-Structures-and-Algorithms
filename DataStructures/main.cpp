#include <iostream>
#include "LinkedList/DLL/DLL_Iterator.h"
#include "LinkedList/DLL/DLL.h"

using std::cout;

int main() {
    DLL dll;

//    dll.addToStart(0);
    dll.addToEnd(10);
//    dll.addToPosition(1, 9);
//    dll.addToPosition(1, 8);
//    dll.addToPosition(1, 7);
//    dll.addToPosition(1, 6);
//    dll.addToPosition(1, 5);
//    dll.addToPosition(1, 4);
//    dll.addToPosition(1, 3);
//    dll.addToPosition(1, 2);
//    dll.addToPosition(1, 1);

    auto iterator = dll.getIterator();
    while (iterator.valid()) {
        cout << iterator.getCurrent() << ' ';
        iterator.next();
    }
    cout << '\n' << '\n';

    cout << dll.removeStart() << '\n';
    cout << dll.removeElement(10) << '\n';
    cout << dll.removeElement(6) << '\n';
//    dll.removeElement(4);

    iterator.first();
    while (iterator.valid()) {
        cout << iterator.getCurrent() << ' ';
        iterator.next();
    }

    return 0;
}
