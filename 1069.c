#include <stdio.h>
#include <stdlib.h>

int main(){
    int number_lines = 0;
    scanf("%d", &number_lines);  // numero de casos

    int* answer = (int*)malloc(sizeof(int) * number_lines); 

    for (int i = 0; i < number_lines; ++i) {
        int number_left = 0, number_right = 0;
        char temp;
        
        while ((temp = getchar()) != '\n' && temp != EOF);  
        while ((temp = getchar()) != '\n' && temp != EOF) {
            if (temp == '<') ++number_left;
            else if (temp == '>') ++number_right;
        }

        answer[i] = 0;
        while (number_left > 0 && number_right > 0) {
            number_left--;
            number_right--;
            answer[i]++; 
        }
    }

    for (int i = 0; i < number_lines; ++i) {
        printf("%d\n", answer[i]);
    }

    free(answer);  
    return 0;
}
