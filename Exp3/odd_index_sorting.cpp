#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    vector<int> temp(high - low + 1);

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) 
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];

    for (int t = low; t <= high; ++t)
        arr[t] = temp[t - low];
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void sortOddIndices(vector<int> &arr) {
    vector<int> oddIndexValues;
    for (int i = 0; i < arr.size(); i += 2) {
        oddIndexValues.push_back(arr[i]);
    }
    mergeSort(oddIndexValues, 0, oddIndexValues.size() - 1);
    int k = 0;
    for (int i = 0; i < arr.size(); i += 2) {
        arr[i] = oddIndexValues[k++];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    clock_t start = clock();
    sortOddIndices(arr);
    clock_t end = clock();
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\nTime taken: "<<(double)(end-start)/CLOCKS_PER_SEC;
    return 0;
}