class Sort():
    def __init__(self, li):
        self.li = li

    def bubble_sort(self):
        n = len(self.li)

        for i in range(n - 1):
            for j in range(0, n - i - 1):
                if self.li[j] > self.li[j + 1]:
                    self.li[j], self.li[j + 1] = self.li[j + 1], self.li[j]

    def insertion_sort(self):
        for i in range(1, len(self.li)):
            key = self.li[i]

            # Move elements of arr[0..i-1], that are
            # greater than key, to one position ahead
            # of their current position
            j = i - 1
            while j >= 0 and key < self.li[j]:
                self.li[j + 1] = self.li[j]
                j -= 1
            self.li[j + 1] = key

    def selection_sort(self):
        n = len(self.li)
        for i in range(n):
            index_min = i
            for j in range(i + 1, n):
                if self.li[j] < self.li[index_min]:
                    index_min = j

            self.li[i], self.li[index_min] = self.li[index_min], self.li[i]

    def __split(self, li):
        mid = len(li) // 2
        left = li[:mid]
        right = li[mid:]

        return left, right

    def __merge(self, left, right):
        l = []
        i = 0
        j = 0

        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                l.append(left[i])
                i += 1
            else:
                l.append(right[j])
                j += 1

        while i < len(left):
            l.append(left[i])
            i += 1

        while j < len(right):
            l.append(right[j])
            j += 1

        return l

    def merge_sort(self, li):
        if len(li) <= 1:
            return li

        left_half, right_half = self.__split(li)
        left = self.merge_sort(left_half)
        right = self.merge_sort(right_half)

        return self.__merge(left, right)


while True:
    # 4, 84, 834, 842, 28, 938, 284
    li = list(map(int, input('Enter an unsorted list: ').split(", ")))
    info = '''
which sort you want to perform?
click 1 for bubble sort
click 2 for insertion sort
click 3 for selection sort
click 4 for merge sort
    '''
    print(info)
    option = int(input('Enter 1, 2, 3 or 4: '))
    sort = Sort(li)
    if option == 1:
        print(f"Before Bubble sort: {li}")
        sort.bubble_sort()
        print(f"After Bubble sort: {li}")
    elif option == 2:
        print(f"Before Selection sort: {li}")
        sort.selection_sort()
        print(f"After Selection sort: {li}")
    elif option == 3:
        print(f"Before Insertion sort: {li}")
        sort.insertion_sort()
        print(f"After Insertion sort: {li}")
    elif option == 4:
        print(f"Before Merge sort: {li}")
        li = sort.merge_sort(li)
        print(f"After Merge sort: {li}")

