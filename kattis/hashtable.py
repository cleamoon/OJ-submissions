class Hashtable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size
        print("New size: ", size)

    def store(self, key, data):
        index = self.hashfunction(key)
        if self.table[index] is None:
            self.table[index] = (key, data)
            print(key + " <- " + str(data))
        else:
            if self.table[index][0] == key:
                self.table[index] = (key, data)
                print(key + " <- " + str(data))
            else:
                while self.table[index] is not None:
                    index += 1
                    if index == self.size:
                        index = 0
                self.table[index] = (key, data)
                print(key + " <- " + str(data))

    def search(self, key):
        index = self.hashfunction(key)
        while self.table[index] is not None:
            if self.table[index][0] == key:
                print(key + ": " + str(self.table[index][1]))
                return self.table[index][1]
            index += 1
            if index == self.size:
                index = 0
        else:
            print("KeyError: ", key)
            raise KeyError

    def hashfunction(self, key):
        return sum([ord(c) for c in key]) % self.size
