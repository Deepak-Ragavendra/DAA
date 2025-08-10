#include<bits/stdc++.h>

using namespace std;

int cutrod(int c,int prices[]){
    if(c==0) return 0;
    int t=0;
    for(int i=1;i<=c;i++){
        t=max(t,prices[i-1]+cutrod(c-i,prices));
    }
    return t;
}

int main(){
    int n;
    cin>>n;
    int prices[n];
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    int c;
    cin>>c;
    clock_t start=clock();
    int tot=cutrod(c,prices);
    cout<<tot;
}