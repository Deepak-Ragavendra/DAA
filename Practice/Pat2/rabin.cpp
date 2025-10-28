#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

vector<pair<int,int>> Karp(string t,string p,int d,int q){
    int n=t.length();
    int m=p.length();
    int h=1;
    int thash=0;
    int phash=0;
    int klimit=ceil((2.0*m)/3.0);
    vector<pair<int,int>> partial;

    for(int i=0;i<m-1;i++){
        h=(d*h)%q;
    }

    for(int i=0;i<m;i++){
        phash=(d*phash+p[i])%q;
        thash=(d*thash+t[i])%q;
    }

    for(int s=0;s<=n-m;s++){
        if(phash==thash){
            if(t.substr(s,m)==p){
                cout<<"Pattern found at "<<s<<endl;
                continue;
            }
        }
        for(int k=m-1;k>=klimit;k--){
            if(s+k<=n && t.substr(s,k)==p.substr(0,k)){
                partial.push_back({s,s+k});
                break;
            }
        }
        if(s<n-m){
            thash=(d*(thash-t[s]*h)+t[s+m])%q;
            if(thash<0){
                thash+=q;
            }
        }
    }
    return partial;
}

int main(){
    int d=256;
    int q=101;
    string t,p;
    cin>>t;
    cin>>p;
    vector<pair<int,int>> partial=Karp(t,p,d,q);
    for(pair<int,int> x:partial){
        cout<<x.first<<" "<<x.second<<endl;
    }
}