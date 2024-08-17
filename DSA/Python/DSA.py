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


# Python


# lowest_value()
# fibonacci()
# fibonacci_using_recursion()
# print("19th fibonacci =", nthFibonacci(19))
# bubble_sort()
bubble_sort_improved()
