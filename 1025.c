#include <stdio.h>

void quicksort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[right];  
    int i = left - 1;  

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    int pivot_index = i + 1;
    quicksort(arr, left, pivot_index - 1);
    quicksort(arr, pivot_index + 1, right);
}

int binary_search_first(int arr[], int size, int target) {
    int left = 0, right = size - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int N, Q, case_num = 1;

    while (scanf("%d %d", &N, &Q) && (N != 0 || Q != 0)) {
        int marbles[N];

        for (int i = 0; i < N; i++) {
            scanf("%d", &marbles[i]);
        }

        quicksort(marbles, 0, N - 1);  // Sort the marbles

        printf("CASE# %d:\n", case_num++);

        for (int i = 0; i < Q; i++) {
            int query;
            scanf("%d", &query);
            
            int index = binary_search_first(marbles, N, query);

            if (index != -1) {
                printf("%d found at %d\n", query, index + 1);
            } else {
                printf("%d not found\n", query);
            }
        }
    }
    
    return 0;
}
