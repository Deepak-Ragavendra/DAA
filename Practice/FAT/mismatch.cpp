#include<iostream>
#include<vector>

using namespace std;

int main(){
    string a,b;
    cin>>a;
    cin>>b;
    int k;
    cin>>k;
    int n=a.length();
    int m=b.length();
    int starta=-1,startb=-1;
    int maxlen=INT_MIN;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    vector<vector<int>> mismatch(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                mismatch[i][j]=mismatch[i-1][j-1];
            }
            else{
                dp[i][j]=1+dp[i-1][j-1];
                mismatch[i][j]=1+mismatch[i-1][j-1];
                if(mismatch[i][j]>k){
                    mismatch[i][j]--;
                    dp[i][j]--;
                }
            }
            if(maxlen<dp[i][j]){
                maxlen=dp[i][j];
                starta=i-dp[i][j];
                startb=j-dp[i][j];
            }
        }
    }
    cout<<a.substr(starta,maxlen)<<" "<<b.substr(startb,maxlen);
    cout<<endl;
    cout<<"Length "<<maxlen;
    return 0;
}