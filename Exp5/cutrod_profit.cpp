#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCutRecTopDown(vector<int> &prices,int c,int cost) {
    if (c==0) return 0;
    int m=INT_MIN;
    for (int i=1;i<=c;i++){
        int v=prices[i-1]+rodCutRecTopDown(prices,c-i,cost);
        if (i!=c) v-=cost;
        m=max(m,v);
    }
    return m;
}

int rodCutMemo(vector<int> &prices,int c,int cost,vector<int> &dp) {
    if (c==0) return 0;
    if (dp[c]!=-1) return dp[c];
    int m=INT_MIN;
    for (int i=1;i<=c;i++){
        int v=prices[i-1]+rodCutMemo(prices,c-i,cost,dp);
        if(i!=c) v-=cost;
        m=max(m, v);
    }
    return dp[c]=m;
}

int rodCutBottomUp(vector<int> &prices,int c,int cost) {
    vector<int> dp(c+1,0);
    vector<int> cut(c+1,0);

    for (int i=1;i<=c;i++) {
        int m=INT_MIN;
        for (int j=1;j<=i;j++) {
            int v=prices[j-1]+dp[i-j];
            if (j!=i) v-=cost;
            if (v>m) {
                m=v;
                cut[i]=j;
            }
        }
        dp[i]=m;
    }

    int t=c;
    cout<<"(Cuts: ";
    while (t>0) {
        cout<<cut[t]<<" ";
        t-=cut[t];
    }
    cout<<") ";
    return dp[c];
}

int main() {
    int n;
    cin>>n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    int c,cost;
    cout<<"Rod Length: ";
    cin>>c;
    cout<<"Cutting Cost: ";
    cin>>cost;
    int tot1=rodCutRecTopDown(prices, c, cost);
    cout<<"Recursive Top-Down Revenue: "<<tot1<<endl;
    vector<int> dp(c+1,-1);
    int tot2=rodCutMemo(prices,c,cost,dp);
    cout<<"Memoized Top-Down Revenue: "<<tot2<<endl;
    cout<<"Extended Bottom-Up Revenue: "<<rodCutBottomUp(prices,c,cost)<<endl;
    return 0;
}