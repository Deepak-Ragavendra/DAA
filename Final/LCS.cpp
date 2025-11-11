#include<iostream>
#include<vector>
#include<set>

using namespace std;

void find_subsequence(string a){
    int n=a.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==a[j-1] && i!=j){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][n]<<" ";

    set<string> seen,repeated;
    for(int i=0;i<n;i++){
        string temp;
        for(int j=i;j<n;j++){
            temp+=a[j];
            if(seen.count(temp)){
                repeated.insert(temp);
            }
            else{
                seen.insert(temp);
            }
        }
    }
    cout<<repeated.size();

}

int main(){
    string a;
    cin>>a;
    find_subsequence(a);
}