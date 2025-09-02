#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    string expr;
    long long c;
};

vector<Matrix> solve(vector<int>& arr,int l,int r){
    vector<Matrix> res;
    if(l+1==r){
        string name="A"+to_string(l);
        res.push_back({name,0});
        return res;
    }
    for(int k=l+1;k<r;k++){
        vector<Matrix> L=solve(arr,l,k);
        vector<Matrix> R=solve(arr,k,r);
        for(auto &x:L){
            for(auto &y:R){
                string expr="("+x.expr+"*"+y.expr+")";
                long long c=x.c+y.c+(long long)arr[l-1]*arr[k-1]*arr[r-1];
                res.push_back({expr,c});
            }
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<Matrix> ans=solve(arr,1,n);
    cout<<"Output:"<<endl;
    cout<<ans.size()<<endl;
    for(auto &m:ans){
        cout<<m.expr<<endl;
        cout<<m.c<<endl;
    }
    return 0;
}
