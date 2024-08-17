#include <stdio.h>
#include <stdbool.h>

void lowest_value();
void fibonacci();
void fibonacci_using_recursion();
void fib_recur(int, int, int);
int nth_fibonacci(int n);
void bubble_sort();
void bubble_sort_improved();

int main()
{
    // lowest_value();
    // fibonacci();
    // fibonacci_using_recursion();
    // printf("19th fibonacci = %d\n", nth_fibonacci(19));
    // bubble_sort();
    bubble_sort_improved();

    return 0;
}

void lowest_value()
{
    int my_array[] = {7, 12, 9, 4, 11};

    int size = sizeof(my_array) / sizeof(my_array[0]);

    int min_val = my_array[0];

    for (int i = 0; i < size; i++)
    {
        if (my_array[i] < min_val)
        {
            min_val = my_array[i];
        }
    }

    printf("Lowest value: %d\n", min_val);
}

void fibonacci()
{
    int prev2 = 0, prev1 = 1;
    int newFib;

    printf("0-fibonacci = %d\n", prev2);
    printf("1-fibonacci = %d\n", prev2);

    for (int i = 2; i <= 19; i++)
    {
        newFib = prev1 + prev2;
        printf("%d-fibonacci = %d\n", i, newFib);
        prev2 = prev1;
        prev1 = newFib;
    }
}

void fibonacci_using_recursion()
{
    printf("%d-fibonacci = %d\n", 0, 0);
    printf("%d-fibonacci = %d\n", 1, 1);
    fib_recur(2, 1, 0);
}

void fib_recur(int count, int prev1, int prev2)
{
    if (count <= 19)
    {
        int newFib = prev1 + prev2;
        printf("%d-fibonacci = %d\n", count, newFib);
        prev2 = prev1;
        prev1 = newFib;
        count++;
        fib_recur(count, prev1, prev2);
    }
    else
    {
        return;
    }
}

int nth_fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return nth_fibonacci(n - 1) + nth_fibonacci(n - 2);
}

void printArray(int my_array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printf("{ %d ", my_array[i]);
        }
        else if (i == n - 1)
        {
            printf("%d }\n", my_array[i]);
        }
        else
        {
            printf("%d ", my_array[i]);
        }
    }
}

void bubble_sort()
{
    int my_array[] = {64, 34, 25, 12, 22, 11, 90, 5};
    int n = sizeof(my_array) / sizeof(int);

    printf("Array: ");
    printArray(my_array, n);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (my_array[j] > my_array[j + 1])
            {
                int temp = my_array[j];
                my_array[j] = my_array[j + 1];
                my_array[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    printArray(my_array, n);
}

void bubble_sort_improved()
{
    int my_array[] = {7, 3, 9, 12, 11};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    printf("Array: ");
    printArray(my_array, n);

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (my_array[j] > my_array[j + 1])
            {
                int temp = my_array[j];
                my_array[j] = my_array[j + 1];
                my_array[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }

    printf("Sorted array: ");
    printArray(my_array, n);
}