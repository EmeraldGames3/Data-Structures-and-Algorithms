#include "Bag.h"

class BagIterator
{
    //DO NOT CHANGE THIS PART
	friend class Bag;

private:
	const Bag& bag;
    int current;

	explicit BagIterator(const Bag& c);
public:
	void first();
	void next();
	[[nodiscard]] TElem getCurrent() const;
	[[nodiscard]] bool valid() const;
};
