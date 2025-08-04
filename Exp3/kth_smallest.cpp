#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<float>& arr, int low, int high) {
    float pivot = arr[high];
    int i = low;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

float quickSelect(vector<float>& arr, int low, int high, int k) {
    if (low == high) return arr[low];
    int pivotIndex = partition(arr, low, high);
    int leftSize = pivotIndex - low + 1;
    if (k == leftSize) {
        return arr[pivotIndex];
    } else if (k < leftSize) {
        return quickSelect(arr, low, pivotIndex - 1, k);
    } else {
        return quickSelect(arr, pivotIndex + 1, high, k - leftSize);
    }
}

int main() {
    int n;
    cin >> n;
    vector<float> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    clock_t start = clock();
    float result = quickSelect(arr, 0, n - 1, k);
    clock_t end = clock();
    cout << result << endl;
    cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    return 0;
}