#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int dp[100][100],bracket[100][100];

int solve(vector<int>&p,int i,int j){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX,k;
    for(int x=i;x<j;x++){
        int cost=solve(p,i,x)+solve(p,x+1,j)+p[i-1]*p[x]*p[j];
        if(cost<ans){
            ans=cost;
            k=x;
        }
    }
    bracket[i][j]=k;
    return dp[i][j]=ans;
}

void print(int i,int j,int &name){
    if(i==j){
        cout<<"A"<<name++;
        return;
    }
    cout<<"(";
    print(i,bracket[i][j],name);
    print(bracket[i][j]+1,j,name);
    cout<<")";
}

int main(){
    int n;
    cin>>n;
    vector<int>p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    memset(dp,-1,sizeof(dp));
    memset(bracket,-1,sizeof(bracket));
    cout<<"Output:"<<endl;
    cout<<solve(p,1,n-1)<<endl;
    int name=1;
    print(1,n-1,name);
    cout<<endl;
    return 0;
}