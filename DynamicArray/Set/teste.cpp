//#include <iostream>
//#include <assert.h>
//#include "Set.h"
//#include "SetIterator.h"
//
//using namespace std;
//void testIteratorSteps(Set& s) {
//    int count = 0;
//    SetIterator si = s.iterator();
//    while (si.valid()) {
//        count++;
//        si.next();
//    }
//    assert(count == s.size());
//}
//int main() {
//    cout << "Test mix" << endl;
//    Set s;
//    int first = 11;
//    int last = 11;
//    int count = 3;
//    for (int i = 0; i < 100; i++) {
//        for (int j = 0; j < count; j++) {
//            s.add(last);
//            last = (last + 7) % 11111;
//        }
//        assert(s.search(first) == true);
//        assert(s.remove(first) == true);
//        first = (first + 7) % 11111;
//        if (i % 10 == 0) {
//            count++;
//        }
//    }
//    while (s.isEmpty() == false) {
//        assert(s.search(first) == true);
//        assert(s.remove(first) == true);
//        first = (first + 7) % 11111;
//
//    }
//
//
//    return 0;
//}