package DSA.Java;

public class DSA {
    public static void main(String[] args) {
        DSA dsa = new DSA();
        // dsa.lowest_value();
        // dsa.fibonacci();
        // dsa.fibonacci_using_recursion();
        // System.out.printf("19th fibonacci = " + dsa.nth_fibonacci(19) + "\n");
        // dsa.bubble_sort();
        // dsa.bubble_sort_improved();
        // dsa.selection_sort();
        // int[] my_array = { 64, 34, 25, 12, 22, 11, 90, 5 };
        // dsa.selection_sort_improved(my_array);
        // dsa.insertion_sort();
        // dsa.insertion_sort_improved();
        // int[] myArray = { 64, 34, 25, 12, 22, 11, 90, 5 };
        // System.out.print("Array: ");
        // int n = myArray.length;
        // dsa.print_array(myArray, n);
        // quicksort(myArray, 0, myArray.length - 1);
        // System.out.print("Sorted array: ");
        // dsa.print_array(myArray, n);
        int[] arr = { 4, 2, 2, 6, 3, 3, 1, 6, 5, 2, 3 };
        System.out.print("Array: ");
        int n = arr.length;
        dsa.print_array(arr, n);
        dsa.countingSort(arr);
        System.out.print("Sorted array: ");
        dsa.print_array(arr, n);
    }

    void countingSort(int[] arr) {
        int max_val = arr[0];
        for (int num : arr) {
            if (num > max_val) {
                max_val = num;
            }
        }

        int[] count = new int[max_val + 1];

        for (int num : arr) {
            count[num]++;
        }

        int index = 0;
        for (int i = 0; i <= max_val; i++) {
            while (count[i] > 0) {
                arr[index++] = i;
                count[i]--;
            }
        }
    }

    void lowest_value() {
        int[] my_array = { 7, 12, 9, 4, 11 };
        int minVal = my_array[0];

        for (int i : my_array) {
            if (i < minVal) {
                minVal = i;
            }
        }

        System.out.println("Lowest value: " + minVal);

    }

    void fibonacci() {
        int prev2 = 0;
        int prev1 = 1;

        System.out.printf(0 + "-fibonacci = " + prev2 + "\n");
        System.out.printf(1 + "-fibonacci = " + prev1 + "\n");

        for (int i = 2; i <= 19; i++) {
            int newFib = prev1 + prev2;
            System.out.printf(i + "-fibonacci = " + newFib + "\n");
            prev2 = prev1;
            prev1 = newFib;
        }
    }

    void fib_recur(int count, int prev1, int prev2) {
        if (count <= 19) {
            int newFib = prev1 + prev2;
            System.out.printf(count + "-fibonacci = " + newFib + "\n");
            prev2 = prev1;
            prev1 = newFib;
            count++;
            fib_recur(count, prev1, prev2);
        } else {
            return;
        }
    }

    void fibonacci_using_recursion() {
        int prev2 = 0;
        int prev1 = 1;

        System.out.printf(0 + "-fibonacci = " + prev2 + "\n");
        System.out.printf(1 + "-fibonacci = " + prev1 + "\n");
        fib_recur(2, prev1, prev2);
    }

    int nth_fibonacci(int n) {
        if (n <= 1)
            return n;
        else
            return nth_fibonacci(n - 1) + nth_fibonacci(n - 2);
    }

    void print_array(int[] array, int n) {
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                System.out.printf("{ " + array[i] + " ");
            } else if (i == n - 1) {
                System.out.printf(array[i] + " }\n");
            } else {
                System.out.printf(array[i] + " ");
            }
        }
    }

    void bubble_sort() {
        int[] my_array = { 64, 34, 25, 12, 22, 11, 90, 5 };
        int n = my_array.length;

        System.out.print("Array: ");
        print_array(my_array, n);

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (my_array[j] > my_array[j + 1]) {
                    int temp = my_array[j];
                    my_array[j] = my_array[j + 1];
                    my_array[j + 1] = temp;
                }
            }
        }

        System.out.print("Sorted Array: ");
        print_array(my_array, n);
    }

    void bubble_sort_improved() {
        int[] my_array = { 7, 3, 9, 12, 11 };
        int n = my_array.length;

        System.out.print("Array: ");
        print_array(my_array, n);

        for (int i = 0; i < n - 1; i++) {
            boolean swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (my_array[j] > my_array[j + 1]) {
                    int temp = my_array[j];
                    my_array[j] = my_array[j + 1];
                    my_array[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }

        System.out.print("Sorted Array: ");
        print_array(my_array, n);
    }

    void selection_sort() {
        int[] my_array = { 64, 34, 25, 5, 22, 11, 90, 12 };
        int n = my_array.length;

        System.out.print("Array: ");
        print_array(my_array, n);

        for (int i = 0; i < n - 1; i++) {
            int min_index = i;
            for (int j = i + 1; j < n; j++) {
                if (my_array[j] < my_array[min_index]) {
                    min_index = j;
                }
            }
            int min_value = my_array[min_index];
            for (int k = min_index; k > i; k--) {
                my_array[k] = my_array[k - 1];
            }
            my_array[i] = min_value;
        }

        System.out.print("Sorted Array: ");
        print_array(my_array, n);
    }

    void selection_sort_improved(int[] my_array) {
        int n = my_array.length;

        System.out.print("Array: ");
        print_array(my_array, n);

        for (int i = 0; i < n; i++) {
            int min_index = i;
            for (int j = i + 1; j < n; j++) {
                if (my_array[j] < my_array[min_index]) {
                    min_index = j;
                }
            }
            int temp = my_array[i];
            my_array[i] = my_array[min_index];
            my_array[min_index] = temp;
        }

        System.out.print("Sorted Array: ");
        print_array(my_array, n);
    }

    void insertion_sort() {
        int[] myArray = { 64, 34, 25, 12, 22, 11, 90, 5 };

        int n = myArray.length;

        System.out.print("Array: ");
        print_array(myArray, n);

        for (int i = 1; i < n; i++) {
            int insert_index = i;
            int current_value = myArray[i];
            int j = i - 1;

            while (j >= 0 && myArray[j] > current_value) {
                myArray[j + 1] = myArray[j];
                insert_index = j;
                j--;
            }
            myArray[insert_index] = current_value;
        }

        System.out.print("Sorted Array: ");
        print_array(myArray, n);
    }

    void insertion_sort_improved() {
        int[] myArray = { 64, 34, 25, 12, 22, 11, 90, 5 };

        int n = myArray.length;

        System.out.print("Array: ");
        print_array(myArray, n);

        for (int i = 1; i < n; i++) {
            int insertIndex = i;
            int currentValue = myArray[i];
            int j = i - 1;

            while (j >= 0 && myArray[j] > currentValue) {
                myArray[j + 1] = myArray[j];
                insertIndex = j;
                j--;
            }
            myArray[insertIndex] = currentValue;
        }

        System.out.print("Sorted Array: ");
        print_array(myArray, n);
    }

    public static int partition(int[] array, int low, int high) {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (array[j] <= pivot) {
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

    public static void quicksort(int[] array, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(array, low, high);
            quicksort(array, low, pivotIndex - 1);
            quicksort(array, pivotIndex + 1, high);
        }
    }
}