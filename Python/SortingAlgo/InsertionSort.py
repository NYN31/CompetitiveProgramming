def insertionsort(li):
    for i in range(1, len(li)):
        key = li[i]

        # Move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        j = i - 1
        while j >= 0 and key < li[j]:
            li[j + 1] = li[j]
            j -= 1
        li[j + 1] = key
    

arr = [4, 84, 834, 842, 28, 938, 284]
insertionsort(arr)
print(arr)
