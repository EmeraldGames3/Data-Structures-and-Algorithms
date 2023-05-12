#include <assert.h>
#include "Matrix.h"
#include <MatrixIterator.h>

using namespace std;

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
    MatrixIterator it(m);
    it.first();
    if (it.valid()) {
        assert(it.getCurrent() == NULL_TELEM);
    }
    it.next_i();
    it.next_i();
    it.next_i();
    it.next_i();
    it.next_i();
    it.next_i();
    it.next_j();
    assert(it.getCurrent() == 6);
}