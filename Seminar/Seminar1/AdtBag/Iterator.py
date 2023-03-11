class Iterator:
    def __init__(self, bag):
        self.i = 0 if bag.size() > 0 else None
        self.bag = bag

    def valid(self):
        return self.i in range(self.bag.size())

    def first(self):
        return self.bag.lst[0] if self.valid() else None

    def next(self):
        if self.valid():
            self.i += 1
            return self.i

        raise AttributeError("Invalid")

    def getCurrent(self):
        if self.valid():
            return self.bag[self.i]

        raise Exception
