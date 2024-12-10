#include <stdio.h>
#include <time.h>

void Merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid; 
    
    int L[n1], R[n2]; // temporary arrays
    
    // Copies elements to temporary arrays:
    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int left, int right){
    if(left < right){
        int middle = left + (right - left) / 2;
        
        // Divide the array in two halves:
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        
        // Mescla as metades ordenadas
        Merge(arr, left, middle, right);
    }
}

int main(){
    int k = 1;
    srand(time(0));

    int arr[500000];

    for(int i = 0; i < 500000; i++) arr[i] = rand() % 1000;
    int n = 20000 * k;

    clock_t start = clock();

    mergeSort(arr, 0, n - 1);

    clock_t end = clock();

    return 0;
}
