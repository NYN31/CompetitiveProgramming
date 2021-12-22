class Node:
    def __init__(self, value):
        self.next = None
        self.prev = None
        self.val = value


class DoubleLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.previous_node = None
        self.size = 0

    def add(self, val):
        node = Node(val)
        if self.tail is None:
            self.head = node
            self.tail = node
            self.size += 1
        else:
            self.tail.next = node # initialize last node's next pointer by new node's pointer
            node.prev = self.tail
            self.tail = node # new tail node
            self.size += 1

    def add_front(self, val):
        node = Node(val)
        if self.tail is None:
            self.head = node
            self.tail = node
            self.size += 1
        else:
            node.next = self.head
            self.head = node
            self.size += 1

    def __remove_node(self, node):
            if node.prev is None:
                self.head = node.next
            else:
                node.prev.next = node.next

            if node.next is None:
                self.tail = node.prev
            else:
                node.next.prev = node.prev

            self.size -= 1

    def remove(self, value):
        node = self.head
        while node is not None:
            if node.val == value:
                self.__remove_node(node)
            node = node.next

    def pop_back(self):
        if self.tail is not None:
            last = self.tail.val
            self.__remove_node(self.tail)
            return last

    def pop_front(self):
        if self.head is not None:
            first = self.head.val
            self.__remove_node(self.head)
            return first
    
    def peek_back(self):
        if self.tail is not None:
            return self.tail.val
    
    def peek_front(self):
        if self.head is not None:
            return self.head.val

    def reverse(self):
        vals = []
        node = self.head
        while node is not None:
            vals.append(node.val)
            node = node.next
        return vals[::-1]

    def count(self, value):
        node = self.head
        total = 0
        while node is not None:
            if node.val == value:
                total += 1
            node = node.next
        return total

    def find(self, value):
        node = self.head
        index = -1
        flag = False
        while node is not None:
            index += 1
            if node.val == value:
                flag = True
                break
            node = node.next

        if flag is False:
            index = -1
        return index

    def __str__(self):
        vals = []
        node = self.head
        while node is not None:
            vals.append(node.val)
            node = node.next
        return f"[{', '.join(str(val) for val in vals)}]"

# add()
# remove()
# pop_front()
# pop_back()
# reverse()
# count()
# find()
# peek_back()
# peek_front()

# size

# my_list = DoubleLinkedList()
# my_list.add(1)
# my_list.add(3)
# my_list.add(7)
# my_list.add(5)
# my_list.add(2)
# print(my_list)
# my_list.add_front(334)
# print(my_list)

