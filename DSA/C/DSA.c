#include <stdio.h>
#include <stdbool.h>

void lowest_value();
void printArray(int my_array[], int n);
void fibonacci();
void fibonacci_using_recursion();
void fib_recur(int, int, int);
int nth_fibonacci(int n);
void bubble_sort();
void bubble_sort_improved();
void selection_sort();
void selection_sort_improved(int n, int my_array[]);
void insertion_sort();
void insertion_sort_improved();
void quicksort(int array[], int low, int high);
int partition(int array[], int low, int high);

/*

void almashtirish(int massiv[], int uzunlik)
{
    int *birinchi = &massiv[0];
    int *oxirgi = &massiv[uzunlik - 1];

    *birinchi = *birinchi + *oxirgi;
    *oxirgi = *birinchi - *oxirgi;
    *birinchi = *birinchi - *oxirgi;
}

*/

int main()
{
    // lowest_value();
    // fibonacci();
    // fibonacci_using_recursion();
    // printf("19th fibonacci = %d\n", nth_fibonacci(19));
    // bubble_sort();
    // bubble_sort_improved();
    // selection_sort();
    // int my_array[] = {64, 34, 25, 12, 22, 11, 90, 5};
    // int n = sizeof(my_array) / sizeof(my_array[0]);
    // selection_sort_improved(n, my_array);
    // insertion_sort();
    // insertion_sort_improved();
    int myArray[] = {64, 34, 25, 12, 22, 11, 90, 5};
    int n = sizeof(myArray) / sizeof(myArray[0]);
    printf("Array: ");
    printArray(myArray, n);
    quicksort(myArray, 0, n - 1);
    printf("Sorted array: ");
    printArray(myArray, n);

    /*
    int A[5] = {1, 2, 3, 4, 5};
    int uzunlik = sizeof(A) / sizeof(A[0]);
    printArray(A, uzunlik);
    almashtirish(A, uzunlik);
    printArray(A, uzunlik);
    */

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

void selection_sort()
{
    int my_array[] = {64, 34, 25, 5, 22, 11, 90, 12};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    printf("Array: ");
    printArray(my_array, n);

    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (my_array[j] < my_array[min_index])
            {
                min_index = j;
            }
        }
        int min_value = my_array[min_index];
        for (int k = min_index; k > i; k--)
        {
            my_array[k] = my_array[k - 1];
        }
        my_array[i] = min_value;
    }

    printf("Sorted Array: ");
    printArray(my_array, n);
}

void selection_sort_improved(int n, int my_array[])
{
    printf("Array: ");
    printArray(my_array, n);

    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (my_array[j] < my_array[min_index])
            {
                min_index = j;
            }
        }
        int temp = my_array[i];
        my_array[i] = my_array[min_index];
        my_array[min_index] = temp;
    }

    printf("Sorted array: ");
    printArray(my_array, n);
}

void insertion_sort()
{
    int myArray[] = {64, 34, 25, 12, 22, 11, 90, 5};

    int n = sizeof(myArray) / sizeof(myArray[0]);

    printf("Array: ");
    printArray(myArray, n);

    for (int i = 1; i < n; i++)
    {
        int insert_index = i;
        int current_value = myArray[i];
        int j = i - 1;

        while (j >= 0 && myArray[j] > current_value)
        {
            myArray[j + 1] = myArray[j];
            insert_index = j;
            j--;
        }
        myArray[insert_index] = current_value;
    }

    printf("Sorted array: ");
    printArray(myArray, n);
}

void insertion_sort_improved()
{
    int myArray[] = {64, 34, 25, 12, 22, 11, 90, 5};
    int n = sizeof(myArray) / sizeof(myArray[0]);

    printf("Array: ");
    printArray(myArray, n);

    for (int i = 1; i < n; i++)
    {
        int insertIndex = i;
        int currentValue = myArray[i];
        int j = i - 1;

        while (j >= 0 && myArray[j] > currentValue)
        {
            myArray[j + 1] = myArray[j];
            insertIndex = j;
            j--;
        }
        myArray[insertIndex] = currentValue;
    }

    printf("Sorted array: ");
    printArray(myArray, n);
}

void quicksort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(array, low, high);
        quicksort(array, low, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, high);
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}