#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m,a;
    cin>>n>>m;
    vector<vector<int>> bar(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>bar[i][j];
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int maxprofit=bar[i][j];
            for(int k=1;k<i;k++){
                maxprofit=max(maxprofit,bar[k][j]+bar[i-k][j]);
            }
            for(int k=1;k<j;k++){
                maxprofit=max(maxprofit,bar[i][k]+bar[i][j-k]);
            }
            dp[i][j]=maxprofit;
        }
    }
    cout<<dp[n][m]<<endl;
}