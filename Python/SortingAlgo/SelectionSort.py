def selection_sort(li):
    n = len(li)
    for i in range(n):
        index_min = i
        for j in range(i + 1, n):
            if li[j] < li[index_min]:
                index_min = j

        li[i], li[index_min] = li[index_min], li[i]


li = [4, 84, 834, 842, 28, 938, 284]
selection_sort(li)
for i in range(len(li)):
    print("%d " % li[i])
