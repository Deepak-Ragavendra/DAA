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
        m=max(m,p[n-i]+cutrodmemo(n-i,p,dp));
    }
    return dp[n]=m;
}

int cutrodtable(int n,int p[],vector<int> dp){
    if(n==0) return 0;
    
}