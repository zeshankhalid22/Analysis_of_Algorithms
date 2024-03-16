#include<iostream>
#include "vector"
using namespace std;

vector<int> count_sort(vector<int>& inputArr) {
    int n = inputArr.size();

    // * 1. Find the Largest Element
    int k = 0;
    for(int i=0;i<n;i++)
        k = max(k, inputArr[i]);

    // Initialize count array with 0 of size k.
        // j from inputArr appeared countArr[j] times totally
    vector<int> countArr(k+1, 0); // 1-based index
    // * 2. Mapping each element of inputArr to countArr
    for(int i=0;i<n;i++)
        countArr[inputArr[i]]++;

    // * 3. Calculate Prefix sum at every index of count array (use countArr too here)
        // means there are countArr[i] elems less than or equal to i
    for(int i=1;i<=k;i++)
        countArr[i] += countArr[i-1];

    // * 4. Create output array from countArr
    vector<int> outputArr(n);
    for(int i=n-1;i>=0;i--) {
        outputArr[countArr[inputArr[i]] - 1] = inputArr[i];

        countArr[inputArr[i]]--;
    }
    return outputArr;
}

int main () {
    vector<int> arr = {4,2,3,3,2,5,6,3,6,4};

    arr = count_sort(arr);
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
}
