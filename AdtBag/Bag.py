from Iterator import Iterator


class Bag:
    def __init__(self):
        self.lst = []

    def search(self, element):
        return element in self.lst

    def add(self, element):
        self.lst.append(element)

    def remove(self, element):
        if self.search(element):
            self.lst.remove(element)

        return self.search(element)

    def size(self):
        return len(self.lst)

    def nrOccurrences(self, element):
        counter = 0

        for e in self.lst:
            if e == element:
                counter += 1

        return counter

    def destroy(self):
        del self.lst

    def iterator(self):
        return Iterator(self)
