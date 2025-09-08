#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int cutrod(int n,int p[]){
    if(n==0) return 0;
    int m=0;
    for(int i=1;i<=n;i++){
        m=max(m,p[i-1]+cutrod(n-i,p));
    }
    return m;

}

int cutrodmemo(int n,int p[],unordered_map<int,int> dp){
    if(n==0) return 0;
    if(dp.count(n)) return dp[n];
    int m=0;
    for(int i=1;i<=n;i++){
        m=max(m,p[n-1]+cutrodmemo(n-i,p,dp));
    }
    return dp[n]=m;
}

int cutrodtable(int n,int p[],vector<int> prices){
    if(n==0) return 0;
    vector<int> dp(c+1,0);
    vector<int> cut(c+1,0);
    for(int i=1;i<=c;i++){
        int m=INT_MIN;
        for(int j=1;j<=i;j++){
            if(prices[j-1]+dp[i-j]>m){
                m=prices[j-1]+dp[i-j];
                cut[i]=j;
            }
        }
        dp[i]=m;
    }
    int t=c;
    while(t>0){
        cout<<cut[t]<<endl;
        t-=cut[t];
    }
    return dp[c];
    
}