#include <stdio.h>
#include <time.h>  // Para medir o tempo

// Função de troca
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivô é o último elemento
    int i = (low - 1);      // Índice do menor elemento

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {  // Elemento menor que o pivô
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Coloca o pivô na posição correta
    return (i + 1);
}

// Função principal de Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Índice do pivô

        // Ordena as partes
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    printArray(arr, n);

    // Marca o tempo de início
    clock_t start = clock();
    
    quickSort(arr, 0, n - 1);
    
    // Marca o tempo de fim
    clock_t end = clock();

    printf("Array ordenado: ");
    printArray(arr, n);

    // Calcula o tempo de execução
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.6f segundos\n", time_taken);

    return 0;
}
