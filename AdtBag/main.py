from Bag import Bag
from Iterator import Iterator


def main():
    b = Bag()

    b.add(1)
    b.add(1)
    b.add(1)
    b.nrOccurrences(1)
    b.add(2)

    assert b.size() == 4
    assert b.search(2)
    assert b.nrOccurrences(1) == 3

    b.remove(2)
    assert not b.search(2)

    i = b.iterator()

    assert type(i) == Iterator
    assert i.bag == b
    assert i.first() == b.lst[0]
    i.next()
    assert i.i == 1
    i.next()
    i.next()

    try:
        i.next()
        i.next()
        i.next()
        assert False
    except:
        b.destroy()

        try:
            b.lst

        except:
            # The delete method is implemented by pythons garbage collector by default
            del b

            try:
                b
            except NameError:
                pass


main()
