#
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 1. Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

      
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 2. Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

// Utility function for Quick Sort to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 3. Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Initializing separate arrays for each sorting test
    int arr1[] = {64, 25, 12, 22, 11, 90, 3};
    int arr2[] = {64, 25, 12, 22, 11, 90, 3};
    int arr3[] = {64, 25, 12, 22, 11, 90, 3};
    
    int n = sizeof(arr1) / sizeof(arr1[0]);

    printf("Original array: \n");
    printArray(arr1, n);
    printf("\n");

    // Test Insertion Sort on arr1
    insertionSort(arr1, n);
    printf("Sorted using Insertion Sort: \n");
    printArray(arr1, n);

    // Test Selection Sort on arr2
    selectionSort(arr2, n);
    printf("Sorted using Selection Sort: \n");
    printArray(arr2, n);

    // Test Quick Sort on arr3
    quickSort(arr3, 0, n - 1);
    printf("Sorted using Quick Sort: \n");
    printArray(arr3, n);

    return 0;
}