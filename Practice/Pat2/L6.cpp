#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    string X;
    string Y;
    cin>>X;
    cin>>Y;
    int n=X.length();
    int m=Y.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(X[i]==Y[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    vector<char> lcs;
    int i=n;
    int j=m;
    while(i>=0 && j>=0){
        if(X[i]==Y[j]){
            lcs.push_back(X[i]);
            i--;
            j--;
        }
        else if(dp[i][j-1]>=dp[i-1][j]){
            j--;
        }
        else{
            i--;
        }
    }
    reverse(lcs.begin(),lcs.end());
    

    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> lis(1,n),prev(-1,n);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && lis[i]<lis[j]+1){
                lis[i]=lis[j]+1;
                prev[j]=i;
            }
        }
    }
    int maxlen=lis[0];
    int idx=0;
    for(int i=0;i<n;i++){
        if(maxlen<lis[i]){
            maxlen=lis[i];
            idx=i;
        }
    }
    vector<int> l;
    while(idx!=-1){
        l.push_back(arr[idx]);
        idx=prev[idx];
    }
    reverse(l.begin(),l.end());
    
}