#include <stdio.h>

int main() {
    int X;
    scanf("%d", &X);
    int proximo_par;

    if (X % 2 == 0) {
        proximo_par = X + 2;
    } else { 
        proximo_par = X + 1;
    }

    printf("%d\n", proximo_par);

    return 0;
}
