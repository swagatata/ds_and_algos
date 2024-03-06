# sort_algo.py

def bubble_sort(list):
    for i in range(len(list) - 1):
        for j in range(len(list) - i - 1):
            if list[j] > list[j + 1]:
                list[j], list[j + 1] = list[j + 1], list[j]

    return list


def insertion_sort(list):
    for i in range(1, len(list)):
        key = list[i]
        j = i - 1
        while j >= 0 and list[j] > key:
            list[j + 1] = list[j]
            j -= 1
        list[j + 1] = key

    return list


def selection_sort(list):
    for i in range(len(list) - 1):
        min_idx = i
        for j in range(i + 1, len(list)):
            if list[j] < list[min_idx]:
                min_idx = j

        list[i], list[min_idx] = list[min_idx], list[i]

    return list


def merge_sort(list):
    if len(list) <= 1:
        return list

    mid = len(list) // 2
    left = merge_sort(list[:mid])
    right = merge_sort(list[mid:])

    return merge(left, right)


def merge(left, right):
    result = []
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result += left[i:]
    result += right[j:]

    return result

def quick_sort(list):
    # decide pivot
    # put it in the right place
    # recursion
    length = len(list)
    if length  < 2:
        return list
    
    pivot = length - 1
    left = -1
    i = 0
    for i in range(length):
        if i >= pivot:
            break
        if list[i] < list[pivot]:
            left += 1
            # swap
            if i == left:
                continue
            temp = list[left]
            list[left] = list[i]
            list[i] = temp
    
    left += 1
    if left == length-1:
        return list
    temp = list[left]
    list[left] = list[pivot]
    list[pivot] = temp
    
    quick_sort(list[0:left])
    quick_sort(list[left+1:])
    return list
    
            
