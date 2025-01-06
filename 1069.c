#include <stdio.h>
#include <stdlib.h>

int main(){
    int number_lines = 0;
    scanf("%d", &number_lines);  // Read the number of test cases

    int* answer = (int*)malloc(sizeof(int) * number_lines);  // Allocate memory for the answers

    for (int i = 0; i < number_lines; ++i) {
        int number_left = 0, number_right = 0;
        char temp;
        
        // Consume the newline after the number of test cases and before each string.
        while ((temp = getchar()) != '\n' && temp != EOF);  // Skip any leftover characters (like a newline)

        // Read each test case line
        while ((temp = getchar()) != '\n' && temp != EOF) {
            if (temp == '<') ++number_left;
            else if (temp == '>') ++number_right;
        }

        // Calculate the number of diamonds
        answer[i] = 0;
        while (number_left > 0 && number_right > 0) {
            number_left--;
            number_right--;
            answer[i]++;  // Form one diamond
        }
    }

    // Print the results
    for (int i = 0; i < number_lines; ++i) {
        printf("%d\n", answer[i]);
    }

    free(answer);  // Don't forget to free the allocated memory
    return 0;
}
