#include <stdio.h>

// Function to compute GCD (Greatest Common Divisor) using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N; // Number of test cases
    int N1, D1, N2, D2; // Numerators and denominators
    char op, slash1, slash2; // Operator and slashes

    scanf("%d", &N); // Read number of test cases

    for (int i = 0; i < N; i++) {
        // Read input format: N1 / D1 op N2 / D2
        scanf("%d %c %d %c %d %c %d", &N1, &slash1, &D1, &op, &N2, &slash2, &D2);

        int num, den; // Result numerator and denominator

        // Perform the operation
        if (op == '+') {
            num = N1 * D2 + N2 * D1;
            den = D1 * D2;
        } else if (op == '-') {
            num = N1 * D2 - N2 * D1;
            den = D1 * D2;
        } else if (op == '*') {
            num = N1 * N2;
            den = D1 * D2;
        } else if (op == '/') {
            num = N1 * D2;
            den = N2 * D1;
        }

        // Compute GCD for simplification
        int divisor = gcd(num, den);

        // Simplified fraction
        int simp_num = num / divisor;
        int simp_den = den / divisor;
        
        if (simp_den < 0) {
            simp_den = simp_den * (-1);
            simp_num = simp_num * (-1);
        }

        // Print results
        printf("%d/%d = %d/%d\n", num, den, simp_num, simp_den);
    }

    return 0;
}
