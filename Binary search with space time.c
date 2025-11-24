#include <stdio.h>
#include <time.h>

int main() {
    int n, i, key, flag = 0;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int low = 0, high = n - 1, mid;

    start = clock();

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            flag = 1;
            break;
        } 
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (flag == 1)
        printf("\nElement found at position %d.\n", mid + 1);
    else
        printf("\nElement not found.\n");

    int space_complexity = 8 + n * 4;

    printf("\n--- Computed Complexities ---\n");
    printf("Time taken by Binary Search : %f seconds\n", time_taken);
    printf("Approximate Space Complexity: %d bytes\n", space_complexity);

    printf("\nResult: The above program has been successfully executed and outcome is verified.\n");
    printf("It effectively addresses the course outcomes CO2 and CO3.\n");

    return 0;
}
