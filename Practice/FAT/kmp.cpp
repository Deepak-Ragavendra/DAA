#include<iostream>
#include<vector>

using namespace std;

void lcs(string p,vector<int> &lc){
    int len=0;
    int i=1;
    lc[0]=0;
    while(i<p.length()){
        if(p[i]==p[len]){
            len++;
            lc[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lc[len-1];
            }
            else{
                lc[i]=0;
                i++;
            }
        }
    }
}

vector<int> search(string t,string p){
    int n=t.length();
    int m=p.length();
    vector<int> lc(m);
    vector<int> res;
    lcs(p,lc);
    int i=0;
    int j=0;
    while(i<n){
        if(t[i]==p[j]){
            i++;
            j++;
            if(j==m){
                res.push_back(i-j);
                j=lc[j-1];
            }
        }
        else{
            if(j!=0){
                j=lc[j-1];
            }
            else{
                i++;
            }
        }
    }
    return res;
}

int main(){
    string t,p;
    cin>>t;
    cin>>p;
    vector<int> res=search(t,p);
    for(int i:res){
        cout<<i<<endl;
    }
    return 0;
}