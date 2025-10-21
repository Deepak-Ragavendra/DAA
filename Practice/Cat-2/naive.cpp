#include <bits/stdc++.h>
using namespace std;

void naiveSearch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++)
            if (text[i + j] != pattern[j])
                break;
        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";
    naiveSearch(text, pattern);
}
