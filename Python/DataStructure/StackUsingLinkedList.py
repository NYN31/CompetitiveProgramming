from DoubleLinkedList import DoubleLinkedList


class Stack:
    def __init__(self):
        self.__list = DoubleLinkedList()
    
    def push(self, val):
        self.__list.add(val)

    def pop(self):
        if self.__list.size != 0:
            value = self.__list.pop_back()
            return value
        else:
            f"Can not pop form empty stack"
    
    def is_empty(self):
        return self.__list.size == 0

    def peek_top(self):
        if self.__list.size != 0:
            return self.__list.peek_back()
        else:
            f"Can not peek form empty stack"

    def __len__(self):
        return self.__list.size


# stack = Stack()
# stack.push(5)
# stack.push(2)
# stack.push(8)
# stack.push(6)
#
# print(stack.peek_top())
# print(len(stack))
# val = stack.pop()
# print(val)
# print(len(stack))
