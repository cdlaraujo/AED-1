#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N;
    int N1, D1, N2, D2; 
    char op, slash1, slash2;

    scanf("%d", &N); 
    for (int i = 0; i < N; i++) {

        scanf("%d %c %d %c %d %c %d", &N1, &slash1, &D1, &op, &N2, &slash2, &D2);

        int num, den;

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

        int divisor = gcd(num, den);

        int simp_num = num / divisor;
        int simp_den = den / divisor;
        
        if (simp_den < 0) {
            simp_den = simp_den * (-1);
            simp_num = simp_num * (-1);
        }

        printf("%d/%d = %d/%d\n", num, den, simp_num, simp_den);
    }

    return 0;
}
