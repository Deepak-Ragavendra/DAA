#include <bits/stdc++.h>
using namespace std;

#define d 256

void RabinKarp(string text, string pattern, int q) {
    int n = text.size();
    int m = pattern.size();
    int p = 0, t = 0, h = 1;
    int i, j;
    
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++)
                if (text[i + j] != pattern[j])
                    break;
            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";
    int q = 101; // prime number
    RabinKarp(text, pattern, q);
}
