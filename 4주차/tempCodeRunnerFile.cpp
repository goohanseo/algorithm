#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int middle, int right);
void quickSortLast(int arr[], int left, int right);
void quickSortMedian(int arr[], int left, int right);
void quickSortRandom(int arr[], int left, int right);
void heapSort(int arr[], int n);
void cLibrarySort(int arr[], int n);
void testSortingAlgorithm(char* algorithmName, void (*sortFunc)(int*, int), int dataSize[], int dataSizeLen, int testNum);

int main() {
    int dataSize[] = {1000, 10000, 100000};
    int dataSizeLen = sizeof(dataSize) / sizeof(dataSize[0]);
    int testNum = 10;

    printf("Algorithm      N=1000         N=10000        N=100000\n");
    printf("----------------------------------------------------\n");

    testSortingAlgorithm("BubbleSort", bubbleSort, dataSize, dataSizeLen, testNum);
    testSortingAlgorithm("SelectionSort", selectionSort, dataSize, dataSizeLen, testNum);
    testSortingAlgorithm("InsertionSort", insertionSort, dataSize, dataSizeLen, testNum);
    testSortingAlgorithm("MergeSort", mergeSort, dataSize, dataSizeLen, testNum);
    testSortingAlgorithm("QuickSortLast", quickSortLast, dataSize, dataSizeLen, testNum);
    testSortingAlgorithm("QuickSortMedian", quickSortMedian, dataSize, dataSizeLen, testNum);
    testSortingAlgorithm("QuickSortRandom", quickSortRandom, dataSize, dataSizeLen, testNum);
    testSortingAlgorithm("HeapSort", heapSort, dataSize, dataSizeLen, testNum);
    testSortingAlgorithm("CLibrarySort", cLibrarySort, dataSize, dataSizeLen, testNum);

    return 0;
}

void testSortingAlgorithm(char* algorithmName, void (*sortFunc)(int*, int), int dataSize[], int dataSizeLen, int testNum) {
    printf("%s", algorithmName);

    for (int i = 0; i < dataSizeLen; i++) {
        int n = dataSize[i];
        double totalTime = 0;

        for (int j = 0; j < testNum; j++) {
            int arr[n];

            for (int k = 0; k < n; k++) {
                arr[k] = rand() % n + 1;
            }

            clock_t start = clock();
            (*sortFunc)(arr, n);
            clock_t end = clock();

            double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
            totalTime += timeTaken;
        }

        double averageTime = totalTime / testNum;
        printf("        %.8lf", averageTime);
    }

    printf("\n");
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted subarray
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Swap the minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void quickSortLast(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;

        for (int j = left; j <= right - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = temp;

        int pi = i + 1;

        quickSortLast(arr, left, pi - 1);
        quickSortLast(arr, pi + 1, right);
    }
}
int getMedianIndex(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;

    if (arr[left] <= arr[mid] && arr[left] >= arr[right]) {
        return left;
    }
    else if (arr[left] >= arr[mid] && arr[left] <= arr[right]) {
        return left;
    }
    else if (arr[mid] <= arr[left] && arr[mid] >= arr[right]) {
        return mid;
    }
    else if (arr[mid] >= arr[left] && arr[mid] <= arr[right]) {
        return mid;
    }
    else {
        return right;
    }
}

void quickSortRandom(int arr[], int left, int right) {
    if (left < right) {
        int pivot = left + rand() % (right - left + 1);
        int pivotVal = arr[pivot];
        int i = left - 1;
        int j = right + 1;

        while (1) {
            do {
                i++;
            } while (arr[i] < pivotVal);

            do {
                j--;
            } while (arr[j] > pivotVal);

            if (i >= j) {
                break;
            }

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        quickSortRandom(arr, left, j);
        quickSortRandom(arr, j + 1, right);
    }
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void cLibrarySort(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
}

