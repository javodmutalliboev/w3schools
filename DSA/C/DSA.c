#include <stdio.h>

void lowest_value();
void fibonacci();
void fibonacci_using_recursion();
void fib_recur(int, int, int);

int main()
{
    // lowest_value();
    // fibonacci();
    fibonacci_using_recursion();

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