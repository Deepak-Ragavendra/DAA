#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;

int cutrod_recursive(int c,vector<int> prices){
    if(c==0) return 0;
    int t=0;
    for(int i=1;i<=c;i++){
        t=max(t,prices[i-1]+cutrod_recursive(c-i,prices));
    }
    return t;
}

int cutrodmemo(int c,vector<int> &prices,unordered_map<int,int> &dp){
    if(c==0) return 0;
    if(dp.count(c)) return dp[c];
    int m=INT_MIN;
    for(int i=1;i<=c;i++){
        m=max(m,prices[i-1]+cutrodmemo(c-i,prices,dp));
    }
    return dp[c]=m;
}

int cutrodbottom(int c,vector<int> &prices){
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
    cout<<"(Cuts: ";
    while(t>0){
        cout<<cut[t]<<" ";
        t-=cut[t];
    }
    cout<<") ";
    return dp[c];
}

int main(){
    int n;
    cin>>n;
    int num;
    vector<int> prices;
    for(int i=0;i<n;i++){
        cin>>num;
        prices.push_back(num);
    }
    int c;
    cin>>c;
    int tot1=cutrod_recursive(c,prices);
    unordered_map<int,int> dp;
    int tot2=cutrodmemo(c,prices,dp);
    
    cout<<"Rod Lengths:"<<endl;
    cout<<"Cut rod using Recursive Top Down: "<<tot1<<endl;
    cout<<"Cut rod using Memoized: "<<tot2<<endl;
    cout<<"Cut rod using Bottom up (Tabulation): "<<cutrodbottom(c,prices)<<endl;
}