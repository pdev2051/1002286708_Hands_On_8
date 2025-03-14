import random

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quickselect(arr, low, high, i):
    if low <= high:
        pivot_index = partition(arr, low, high)
        if pivot_index == i:
            return arr[pivot_index]
        elif pivot_index > i:
            return quickselect(arr, low, pivot_index - 1, i)
        else:
            return quickselect(arr, pivot_index + 1, high, i)

def ith_order_statistic(arr, i):
    if i < 0 or i >= len(arr):
        raise ValueError("Index out of bounds")
    return quickselect(arr[:], 0, len(arr) - 1, i)


arr = [11, 5, 6, 9, 7, 12, 27]
i = 5  # Find the 5th order statistic (0-based index, so it's the 6th smallest)
print(f"The {i+1}th smallest element is: {ith_order_statistic(arr, i)}")
