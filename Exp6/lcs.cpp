#include <bits/stdc++.h>
using namespace std;

int main() {
    string X;
    string Y;
    cin>>X;
    cin>>Y;
    int n=X.length();
    int m=Y.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(X[i-1]==Y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    vector<char> res;
    int i=n;
    int j=m;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            res.push_back(X[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(res.begin(),res.end());
    string l="";
    for(char p:res) l+=p;
    cout<<l;
	return 0;
}


