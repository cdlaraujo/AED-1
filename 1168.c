#include <stdio.h>
#include <string.h>
 
int main() {
    int N, num_leds = 0;
    char number[10000] = {'\0'};
    
    scanf("%d", &N);
    
    while (N--) {
        num_leds = 0;
        
        scanf("%s", number);
        for (int i = 0; i < strlen(number); i++) {
            if (number[i] == '1') num_leds += 2;
            if (number[i] == '2') num_leds += 5;
            if (number[i] == '3') num_leds += 5;
            if (number[i] == '4') num_leds += 4;
            if (number[i] == '5') num_leds += 5;
            if (number[i] == '6') num_leds += 6;
            if (number[i] == '7') num_leds += 3;
            if (number[i] == '8') num_leds += 7;
            if (number[i] == '9') num_leds += 6;
            if (number[i] == '0') num_leds += 6;
        }
        printf("%d leds\n", num_leds);
    }

    return 0;
}
