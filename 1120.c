#include <stdio.h>
#include <string.h>

int main() {
    int D;
    char N[101];
    
    while (1) {
        scanf("%d %s", &D, N);
        if (D == 0 && strcmp(N, "0") == 0) {
            break;
        }
        
        char filtered[101];
        int j = 0;
        for (int i = 0; N[i] != '\0'; i++) {
            if (N[i] != (D + '0')) {
                filtered[j++] = N[i];
            }
        }
        filtered[j] = '\0';
        
        if (j == 0) {
            printf("0\n");
            continue;
        }
        
        int k = 0;
        while (k < j && filtered[k] == '0') {
            k++;
        }
        
        if (k == j) {
            printf("0\n");
        } else {
            printf("%s\n", filtered + k);
        }
    }
    
    return 0;
}
