from DoubleLinkedList import DoubleLinkedList


class Queue:
    def __init__(self):
        self.__list = DoubleLinkedList()

    def enqueue(self, val):
        self.__list.add(val)

    def deque(self):
        if self.__list.size != 0:
            value = self.__list.pop_front()
            return value
        else:
            f"Can not delete form empty queue"

    def is_empty(self):
        return self.__list.size == 0

    def peek_front(self):
        if self.__list.size != 0:
            return self.__list.peek_front()
        else:
            f"Can not peek form empty stack"

    def __len__(self):
        return self.__list.size


# queue = Queue()
# queue.enqueue(2)
# queue.enqueue(6)
# queue.enqueue(3)
# queue.enqueue(8)
# queue.enqueue(4)
#
# print(len(queue))
# print(queue.peek_front())
# print(queue.deque())
# print(queue.peek_front())
