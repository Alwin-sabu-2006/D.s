#include <stdio.h>

void bubbleSort(int arr[], int n, long *steps) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*steps)++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n, long *steps) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            (*steps)++;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high, long *steps) {
    int pivot = arr[high];
    int i = (low - 1);
    int j, temp;
    for (j = low; j <= high - 1; j++) {
        (*steps)++;
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high, long *steps) {
    if (low < high) {
        int pi = partition(arr, low, high, steps);
        quickSort(arr, low, pi - 1, steps);
        quickSort(arr, pi + 1, high, steps);
    }
}

void merge(int arr[], int l, int m, int r, long *steps) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        (*steps)++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r, long *steps) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m, steps);
        mergeSort(arr, m + 1, r, steps);
        merge(arr, l, m, r, steps);
    }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long steps_bubble = 0, steps_insertion = 0, steps_quick = 0, steps_merge = 0;

    for (i = 0; i < n; i++) temp[i] = arr[i];
    bubbleSort(temp, n, &steps_bubble);

    for (i = 0; i < n; i++) temp[i] = arr[i];
    insertionSort(temp, n, &steps_insertion);

    for (i = 0; i < n; i++) temp[i] = arr[i];
    quickSort(temp, 0, n - 1, &steps_quick);

    for (i = 0; i < n; i++) temp[i] = arr[i];
    mergeSort(temp, 0, n - 1, &steps_merge);

    printf("\n--- Sorting Comparison (Steps Only) ---\n");
    printf("Algorithm      Steps Taken\n");
    printf("Bubble Sort    %ld\n", steps_bubble);
    printf("Insertion Sort %ld\n", steps_insertion);
    printf("Quick Sort     %ld\n", steps_quick);
    printf("Merge Sort     %ld\n", steps_merge);

  

    return 0;
}
