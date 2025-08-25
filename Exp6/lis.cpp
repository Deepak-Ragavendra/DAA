#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> dp(n,1), prev(n,-1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                prev[i]=j;
            }
        }
    }
    int maxlen=dp[0], maxidx=0;
    for(int i=1;i<n;i++){
        if(dp[i]>maxlen){
            maxlen=dp[i];
            maxidx=i;
        }
    }
    vector<int> lis;
    int idx=maxidx;
    while(idx!=-1){
        lis.push_back(arr[idx]);
        idx=prev[idx];
    }
    reverse(lis.begin(),lis.end());
    cout<<"Longest Increasing Subsequence = ";
    for(int x:lis) cout<<x<<" ";
    cout<<"\nLongest Increasing Subsequence (LIS) Length = "<<maxlen<<endl;

    return 0;
}
