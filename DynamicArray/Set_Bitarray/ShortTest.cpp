#include "ShortTest.h"
#include <assert.h>
#include "Set.h"
#include "SetIterator.h"

void testAll() { 
	Set s;
	assert(s.isEmpty() == true);
	assert(s.size() == 0); 
	assert(s.add(5)==true);
	assert(s.add(1)==true);
	assert(s.add(10)==true);
	assert(s.add(7)==true);
	assert(s.add(1)==false);
	assert(s.add(10)==false);
	assert(s.add(-3)==true);
	assert(s.size() == 5);
	assert(s.search(10) == true);
	assert(s.search(16) == false);
	assert(s.remove(1) == true);
	assert(s.remove(6) == false);
	assert(s.size() == 4);


	SetIterator it = s.iterator();
	it.first();
	int sum = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		sum += e;
		it.next();
	}
	assert(sum == 19);

    // test the intersection method
    Set s2, s3, s4;
    assert(s2.size() == 0);
    assert(s3.size() == 0);

    assert(s2.add(1) == true);
    assert(s2.add(3) == true);
    assert(s2.add(5) == true);
    assert(s2.size() == 3);

    assert(s3.add(2) == true);
    assert(s3.add(4) == true);
    assert(s3.size() == 2);

    s4 = s2.intersection(s3);
    assert(s4.size() == 0);


}

