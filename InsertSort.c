#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5000

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elementos maiores que `key` para a frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    srand(time(0));

    int arr[MAX];

    // Preenche o array com números aleatórios
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 1000;
    }

    clock_t start = clock();  // Medição de tempo

    insertionSort(arr, MAX);  // Ordenação

    clock_t end = clock();  // Fim da medição de tempo

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.6f segundos\n", time_taken);

    // Impressão opcional do array ordenado
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
