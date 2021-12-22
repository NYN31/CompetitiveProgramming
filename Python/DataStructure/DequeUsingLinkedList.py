from DoubleLinkedList import DoubleLinkedList


class Deque:
    def __init__(self):
        self.__list = DoubleLinkedList()

    def push_back(self, val):
        self.__list.add(val)

    def push_front(self, val):
        self.__list.add_front(val)

    def pop_back(self):
        if self.__list.size != 0:
            value = self.__list.pop_back()
            return value
        else:
            f"Can not pop form empty stack"

    def pop_front(self):
        if self.__list.size != 0:
            value = self.__list.pop_front()
            return value
        else:
            f"Can not pop form empty stack"

    def is_empty(self):
        return self.__list.size == 0

    def peek_back(self):
        if self.__list.size != 0:
            return self.__list.peek_back()
        else:
            f"Can not peek form empty stack"

    def peek_front(self):
        if self.__list.size != 0:
            return self.__list.peek_front()
        else:
            f"Can not peek form empty stack"

    def __len__(self):
        return self.__list.size


# deque = Deque()
# deque.push_back(5)
# deque.push_back(2)
# deque.push_back(8)
# deque.push_back(6)
#
# deque.push_front(11)
#
# print(deque.peek_front())
# print(deque.peek_back())
#
# print(len(deque))
# print(deque.pop_back())
# print(deque.pop_front())
# print(len(deque))
