#include <bits/stdc++.h>
using namespace std;

void naiveSearch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    int i=0;
    for (i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++)
            if (text[i + j] != pattern[j])
                break;
        if (j == m)
            cout << "Pattern found at index " << i << endl;
        else{
            int t=j;
            for(int k=t;k>=0;k--){
                if(text[i]!=pattern[j]){
                    i--;
                    j--;
                }
            }
        }
    }
}

int main() {
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";
    naiveSearch(text, pattern);
}
