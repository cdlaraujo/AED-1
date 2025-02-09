#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); 

    for (int i = 0; i < n; i++) {
        char a[4]; 
        scanf("%s", a);

        int x = a[0] - '0'; 
        int y = a[2] - '0'; 
        char c = a[1];    

        if (x == y) {
            printf("%d\n", x * x);
        } else if (c >= 'a' && c <= 'z') {
            printf("%d\n", x + y);
        } else {
            printf("%d\n", y - x);
        }
    }

    return 0;
}
