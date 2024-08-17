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


# lowest_value()
# fibonacci()
fibonacci_using_recursion()
