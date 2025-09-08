#include<iostream>
#include<string>
#include<vector>
using namespace std;

int computeHash(string text,int length){
    int h=0;
    int d=10;
    int q=13;
    for(int i=0;i<length;i++){
        h=(h*d+text[i])%q;
    }
    return h;
}

int countSpurious(string t,string p){
    int d=10;
    int q=13;
    int n=t.length();
    int m=p.length();
    if(m>n) return 0;

    int h=1;
    for(int i=0;i<m-1;i++){
        h=(h*d)%q;
    }
    int thash=computeHash(t,m);
    int phash=computeHash(p,m);
    int s=0;

    for(int i=0;i<=n-m;i++){
        if(thash==phash){
            if(t.substr(i,m)!=p){
                s++;
            }
        }
        if(i<n-m){
            thash=(d*(thash-t[i]*h)+t[i+m])%q;
            if(thash<0) thash+=q;
        }
    }
    return s;
}

int main(){
    int k;
    cin>>k;
    vector<string> t(k),p(k);
    for(int i=0;i<k;i++) cin>>t[i];
    for(int j=0;j<k;j++) cin>>p[j];

    int d=256,q=101;
    int maxh=-1,minh=INT_MAX;
    pair<int,int> maxp,minp;

    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            int h=countSpurious(t[i],p[j]);
            if(h>maxh){
                maxh=h;
                maxp={i,j};
            }
            if(h<minh){
                minh=h;
                minp={i,j};
            }
        }
    }
    cout<<"Max spurious hits: Tuple (T"<<maxp.first+1<<", P"<<maxp.second+1<<") = "<<maxh<<endl;
    cout<<"Min spurious hits: Tuple (T"<<minp.first+1<<", P"<<minp.second+1<<") = "<<minh<<endl;
    return 0;
}
