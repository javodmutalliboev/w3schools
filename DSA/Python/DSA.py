def lowest_value():
    my_array = [7, 12, 9, 4, 11]
    minVal = my_array[0]

    for i in my_array:
        if i < minVal:
            minVal = i

    print("Lowest value:", minVal)


def fibonacci():
    prev2 = 0
    prev1 = 1

    print("0-fibonacci =", prev2)
    print("1-fibonacci =", prev1)
    for nth_fib in range(18):
        new_fib = prev1 + prev2
        print(nth_fib + 2, "\b-fibonacci =", new_fib)
        prev2 = prev1
        prev1 = new_fib


def fibonacci_using_recursion():
    print("0-fibonacci =", 0)
    print("1-fibonacci =", 1)
    count = 2

    def recursion(prev1, prev2):
        nonlocal count
        if count <= 19:
            newFib = prev1 + prev2
            print(count, "\b-fibonacci =", newFib)
            prev2 = prev1
            prev1 = newFib
            count += 1
            recursion(prev1, prev2)
        else:
            return

    recursion(1, 0)


def nthFibonacci(n):
    if n <= 1:
        return n
    else:
        return nthFibonacci(n - 1) + nthFibonacci(n - 2)


def bubble_sort():
    my_array = [64, 34, 25, 12, 22, 11, 90, 5]
    n = len(my_array)

    print("Array:", my_array)

    for i in range(n - 1):
        for j in range(n - i - 1):
            if my_array[j] > my_array[j + 1]:
                my_array[j], my_array[j + 1] = my_array[j + 1], my_array[j]

    print("Sorted array:", my_array)


def bubble_sort_improved():
    my_array = [7, 3, 9, 12, 11]

    print("Array:", my_array)

    n = len(my_array)
    for i in range(n - 1):
        swapped = False
        for j in range(n - i - 1):
            if my_array[j] > my_array[j + 1]:
                my_array[j], my_array[j + 1] = my_array[j + 1], my_array[j]
                swapped = True
        if not swapped:
            break

    print("Sorted array:", my_array)


def selection_sort():
    my_array = [64, 34, 25, 5, 22, 11, 90, 12]

    print("Array:", my_array)

    n = len(my_array)
    # print("n:", n)
    for i in range(n - 1):
        # print("i:", i)
        min_index = i
        for j in range(i + 1, n):
            if my_array[j] < my_array[min_index]:
                min_index = j
        min_value = my_array.pop(min_index)
        my_array.insert(i, min_value)
    print("Sorted array:", my_array)


def selection_sort_improved(my_array: list[int]):
    print("Array:", my_array)

    n = len(my_array)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if my_array[j] < my_array[min_index]:
                min_index = j
        my_array[i], my_array[min_index] = my_array[min_index], my_array[i]

    print("Sorted array:", my_array)


def insertion_sort(my_array: list[int]):
    print("Array:", my_array)

    n = len(my_array)

    for i in range(1, n):
        insert_index = i
        current_value = my_array.pop(i)
        for j in range(i - 1, -1, -1):
            if my_array[j] > current_value:
                insert_index = j
        my_array.insert(insert_index, current_value)

    print("Sorted array:", my_array)


def insertion_sort_improved():
    my_array = [64, 34, 25, 12, 22, 11, 90, 5]

    print("Array:", my_array)

    n = len(my_array)
    for i in range(1, n):
        insert_index = i
        current_value = my_array[i]
        for j in range(i - 1, -1, -1):
            if my_array[j] > current_value:
                my_array[j + 1] = my_array[j]
                insert_index = j
            else:
                break
        my_array[insert_index] = current_value

    print("Sorted array:", my_array)


def partition(array, low, high):
    pivot = array[high]
    i = low - 1

    for j in range(low, high):
        if array[j] <= pivot:
            i += 1
            array[i], array[j] = array[j], array[i]

    array[i + 1], array[high] = array[high], array[i + 1]
    return i + 1


def quicksort(array, low=0, high=None):
    if high is None:
        high = len(array) - 1

    if low < high:
        pivot_index = partition(array, low, high)
        quicksort(array, low, pivot_index - 1)
        quicksort(array, pivot_index + 1, high)


def countingSort(arr: list[int]) -> list[int]:
    max_val = max(arr)
    count = [0] * (max_val + 1)
    while len(arr) > 0:
        num = arr.pop(0)
        count[num] += 1

    for i in range(len(count)):
        while count[i] > 0:
            arr.append(i)
            count[i] -= 1

    return arr


# Python


# lowest_value()
# fibonacci()
# fibonacci_using_recursion()
# print("19th fibonacci =", nthFibonacci(19))
# bubble_sort()
# bubble_sort_improved()
# selection_sort()
# selection_sort_improved([64, 34, 25, 12, 22, 11, 90, 5])
# insertion_sort([64, 34, 25, 12, 22, 11, 90, 5])
# insertion_sort_improved()
# my_array = [64, 34, 25, 12, 22, 11, 90, 5]
# print("Array", my_array)
# quicksort(my_array)
# print("Sorted array:", my_array)
unsortedArr = [4, 2, 2, 6, 3, 3, 1, 6, 5, 2, 3]
print("Unsorted array:", unsortedArr)
sortedArr = countingSort(unsortedArr)
print("Sorted array:", sortedArr)
