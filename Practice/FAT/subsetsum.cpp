#include<iostream>
#include<vector>

using namespace std;

int subset(int n,vector<int> arr,int sum){
    bool dp[n+1][sum+1];
    for(int i=0;i<sum;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<n;i++){
        dp[0][i]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int n,a;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }
    int sum;
    cin>>sum;
    cout<<subset(n,arr,sum)<<endl;
}