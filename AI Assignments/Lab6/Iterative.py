class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            return None

    def is_empty(self):
        return len(self.items) == 0

def towerOfHanoiIterative(n, source_rod, helper_rod, destination_rod):
    stack = Stack()
    stack.push((n, source_rod, helper_rod, destination_rod))

    while not stack.is_empty():
        n, source, helper, destination = stack.pop()

        if n == 1:
            print("Disk moved from", source, "to", destination)
        else:
            stack.push((n - 1, helper, source, destination))
            stack.push((1, source, helper, destination))
            stack.push((n - 1, source, destination, helper))

# Taking the number of disks input
n = int(input("Enter the number of disks: "))

# calling the iterative function
towerOfHanoiIterative(n, "A", "B", "C")
