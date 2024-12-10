#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(0));

    for (int i = 1; i <= 10; i++) {  // Testa diferentes tamanhos de entrada
        int size = i * 5000;  // Aumenta em passos de 5000
        int arr[MAX_SIZE];

        // Preenche o array com valores aleatórios
        for (int j = 0; j < size; j++) {
            arr[j] = rand() % 10000;
        }

        // Medição de tempo
        clock_t start = clock();
        quickSort(arr, 0, size - 1);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Tamanho: %d | Tempo: %.6f segundos\n", size, time_taken);
    }

    return 0;
}
