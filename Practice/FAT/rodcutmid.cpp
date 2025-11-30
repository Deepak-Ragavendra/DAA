#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int cutrod(int l,vector<int> &prices,vector<int> &cutpos){
    if(l==1) return prices[0];
    int maxprofit=prices[l-1];
    if(l>=2){
        int mid=l/2;
        int left=cutrod(mid,prices,cutpos);
        int right=cutrod(l-mid,prices,cutpos);
        int tot=left+right;
        if(maxprofit<tot){
            cutpos[l]=mid;
            maxprofit=tot;
        }
    }
    return maxprofit;
}

void printing(vector<int> cutpos,int l){
    if(cutpos[l]==-1) return;
    if(l<=1) return;
    cout<<cutpos[l]<<" ";
    printing(cutpos,cutpos[l]);
    printing(cutpos,l-cutpos[l]);
}

int main(){
    int n,a;
    cin>>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    int c;
    cin>>c;
    vector<int> dp(c+1,-1);
    cout<<cutrod(c,prices,dp)<<endl;
    printing(dp,c);
    return 0;
}