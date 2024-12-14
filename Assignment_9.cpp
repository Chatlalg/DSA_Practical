/*
Implement Heap sort to sort given set of values using max or min heap.
*/

#include <iostream>
using namespace std;

void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void heapSortMax(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}

void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void heapSortMin(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arrMax[] = { 60, 20, 40, 70, 10 };
    int nMax = sizeof(arrMax) / sizeof(arrMax[0]);

    cout << "MaxHeap:\n";
    heapSortMax(arrMax, nMax);
    cout << "Sorted array (MaxHeap) is \n";
    printArray(arrMax, nMax);

    int arrMin[] = { 60, 20, 70, 30, 10 };
    int nMin = sizeof(arrMin) / sizeof(arrMin[0]);

    cout << "MinHeap:\n";
    heapSortMin(arrMin, nMin);
    cout << "Sorted array (MinHeap) is \n";
    printArray(arrMin, nMin);

    return 0;
}