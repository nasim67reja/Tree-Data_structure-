import math

class heap:
    def __init__(self) -> None:
        self.arr = [None]  # Insert a dummy value to make the heap 1-indexed
        self.size = 0

    # Insertion
    def insert(self, val):
        self.arr.append(val)  # Append the new value at the end of the list
        self.size += 1
        index = self.size

        while index > 1:
            parent = math.trunc(index / 2)

            if self.arr[parent] < self.arr[index]:
                # Swap parent and current index
                self.arr[parent], self.arr[index] = self.arr[index], self.arr[parent]
                index = parent  # Move up the heap
            else:
                break  # If the parent is larger or equal, the heap property is satisfied

    # Printing
    def show(self):
        print(self.arr[1:])  # Skip the dummy value for printing

h = heap()

h.insert(60)
h.insert(20)
h.insert(50)
h.insert(55)
h.insert(30)
h.show()
