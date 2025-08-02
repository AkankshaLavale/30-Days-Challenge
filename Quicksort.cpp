#include <iostream>
using namespace std;

int partition(int arr[], int start, int end) {
    int pos = start;
    for (int i = start; i < end; i++) {  // exclude pivot itself
        if (arr[i] <= arr[end]) {
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
    swap(arr[pos], arr[end]);  // place pivot in correct position
    return pos;
}

void quicksort(int arr[], int start, int end) {
    if (start >= end) return;
    int pivot = partition(arr, start, end);
    quicksort(arr, start, pivot - 1);
    quicksort(arr, pivot + 1, end);
}

int main() {
    int arr[] = {3, 5, 2, 7, 8, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);  

    
    for (int i = 0; i < n; i++)  // Fix: i < n, not <= n
        cout << arr[i] << " ";

    return 0;
}
