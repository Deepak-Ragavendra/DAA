#include <iostream>
#include <ctime>

using namespace std;

int maxDigit(int n) {
    if (n < 10) return n;
    int digits=1;
    int temp=n;
    while (temp>=10) {
        temp/=10;
        digits++;
    }
    int divisor=1;
    for (int i=0;i<digits/2;i++) {
        divisor*=10;
    }
    int left=n/divisor;
    int right=n%divisor;
    int maxLeft=maxDigit(left);
    int maxRight=maxDigit(right);
    return max(maxLeft,maxRight);
}

int main() {
    clock_t start = clock();
    int n;
    cin >> n;
    int result = maxDigit(n);
    if (result >= 8) {
        cout << result << endl;
    } else {
        cout << "Invalid" << endl;
    }
    clock_t end = clock();
    cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    return 0;
}