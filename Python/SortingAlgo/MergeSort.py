def split(List):
    mid = len(List)//2
    left = List[:mid]
    right = List[mid:]

    return left, right


def merge(left, right):
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


def merge_sort(List):
    if len(List) <= 1:
        return List

    left_half, right_half = split(List)
    left = merge_sort(left_half)
    right = merge_sort(right_half)

    return merge(left, right)


arr = [54, 62, 93, 17, 77]
l = merge_sort(arr)
print(l)
