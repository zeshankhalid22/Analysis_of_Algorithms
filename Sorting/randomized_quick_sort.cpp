// Randomized quick sort complexity O(Nlog(N))

#include<iostream>
#include "vector"
#include "ctime"

using namespace std;

// assuming pivot is at last
int partition(vector<int> &arr, int low, int high) {

    int pivotVal = arr[high];
    // I will always hold the 1st element on left side, greater than pivot
    int l = low;
    // I will always <= J
    for (int r = low; r <= high - 1; r++) {
        if (arr[r] < pivotVal) {
            // bringer greater_element(than pivot) on right side(nearer to high)
            swap(arr[l], arr[r]);
            l++;
        }
    }
    // swap 1st greatest element(from left) which is now pivot_index,
    // so pivot divides array into 2 halves
    swap(arr[l], arr[high]);
    // now pivot is at its final position

    // return the updated pivot
    return l;
}

void randomizedQuickSort(vector<int> &arr, int low, int high) {
    if (low >= high)
        return;

    srand(time(NULL));

    int pivot = low + rand() % (high - low + 1);
    // shifting pivot at last position
    swap(arr[pivot], arr[high]);

    pivot = partition(arr, low, high);

    randomizedQuickSort(arr, low, pivot - 1);
    randomizedQuickSort(arr, pivot + 1, high);

}

int main() {
    vector<int> arr = {4,8,3,5,6};

    for (auto &i: arr) {
        cout << i << " ";
    }
    cout << endl;

    randomizedQuickSort(arr, 0, arr.size() - 1);

    for (auto &i: arr) {
        cout << i << " ";
    }

    return 0;
}
