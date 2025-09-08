#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

vector<pair<int,int>> rabinKarpPartial(string &t,string &p,int d,int q){
    int n=t.size();
    int m=p.size();
    vector<pair<int,int>> partialShifts;
    int kLimit=ceil((2.0*m)/3.0);
    int pHash=0,tHash=0,h=1;
    for(int i=0;i<m-1;i++)
        h=(h*d)%q;
    for(int i=0;i<m;i++){
        pHash=(d*pHash+p[i])%q;
        tHash=(d*tHash+t[i])%q;
    }
    for(int s=0;s<=n-m;s++){
        if(pHash==tHash){
            if(t.substr(s,m)==p){
                cout<<"Full shift: "<<s<<endl;
            }
        }
        for(int k=m-1;k>=kLimit;--k){
            if(s+k<=n && p.substr(0,k)==t.substr(s,k)){
                partialShifts.push_back({s,k});
                break;
            }
        }
        if(s<n-m){
            tHash=(d*(tHash-t[s]*h)+t[s+m])%q;
            if(tHash<0) tHash+=q;
        }
    }
    return partialShifts;
}

int main(){
    string t,p;
    cin>>t>>p;
    int d=256;
    int q=101;
    cout<<"Text="<<t<<endl;
    cout<<"Pattern="<<p<<endl;
    vector<pair<int,int>> partials=rabinKarpPartial(t,p,d,q);
    cout<<"Partially valid shifts (shift,k): ";
    for(pair<int,int> x:partials){
        cout<<"("<<x.first<<","<<x.second<<") ";
    }
    cout<<endl;
    return 0;
}