#include <iostream>
#include <vector>
using namespace std;

void findSubsets(int arr[], int n, int sum, vector<int>& current, vector<vector<int>>& result) {
    // Base case
    if (sum == 0) {
        result.push_back(current);
        return;
    }
    if (n == 0)
        return;

    // If current element is greater than sum, skip it
    if (arr[n - 1] > sum) {
        findSubsets(arr, n - 1, sum, current, result);
        return;
    }

    // Case 1: Include current element
    current.push_back(arr[n - 1]);
    findSubsets(arr, n - 1, sum - arr[n - 1], current, result);

    // Case 2: Exclude current element
    current.pop_back();
    findSubsets(arr, n - 1, sum, current, result);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<vector<int>> result;
    vector<int> current;

    findSubsets(arr, n, sum, current, result);

    if (result.empty()) {
        cout << "No subset found" << endl;
    } else {
        cout << "Subsets with sum = " << sum << " are:" << endl;
        for (auto subset : result) {
            cout << "{ ";
            for (int num : subset)
                cout << num << " ";
            cout << "}" << endl;
        }
    }

    return 0;
}
