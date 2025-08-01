#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    vector<int> temp(end - start + 1);

    int left = start, right = mid + 1, index = 0;

    while (left <= mid && right <= end) {
        if (arr[left] <= arr[right]) {
            temp[index] = arr[left];
            index++;
            left++;
        } else {
            temp[index] = arr[right];
            index++;
            right++;
        }
    }

    // Copy remaining elements of left subarray
    while (left <= mid) {
        temp[index] = arr[left];
        index++;
        left++;
    }

    // Copy remaining elements of right subarray
    while (right <= end) {
        temp[index] = arr[right];
        index++;
        right++;
    }

    // Copy temp array back to original array
    for (int i = 0; i < temp.size(); i++) {
        arr[start + i] = temp[i];
    }
}

void mergesort(int arr[], int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;

    // Left half
    mergesort(arr, start, mid);

    // Right half
    mergesort(arr, mid + 1, end);

    // Merge both halves
    merge(arr, start, mid, end);
}

int main() {
    int arr[] = {1, 5, 2, 4, 3, 7, 8, 6, 9, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
