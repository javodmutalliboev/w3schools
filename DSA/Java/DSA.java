package DSA.Java;

public class DSA {
    public static void main(String[] args) {
        DSA dsa = new DSA();
        // dsa.lowest_value();
        // dsa.fibonacci();
        dsa.fibonacci_using_recursion();
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
}