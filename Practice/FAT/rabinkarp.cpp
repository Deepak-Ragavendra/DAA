#include<iostream>
#include<vector>

using namespace std;

void rabin(string text,string pattern,int q){
    int n=text.length();
    int m=pattern.length();
    int t=0,p=0,h=1,d=256;

    for(int i=0;i<m-1;i++){
        h=(h*d)%q;
    }
    for(int i=0;i<m;i++){
        t=(d*t+text[i])%q;
        p=(d*p+pattern[i])%q;
    }
    for(int i=0;i<=n-m;i++){
        if(p=t){
            int j=0;
            for(j=0;j<m;j++){
                if(text[i+j]!=pattern[j]){
                    break;
                }
            }
            if(j==m){
                cout<<"Pattern found at "<<i<<endl;
            }
        }
        if(i<n-m){
            t=(d*(t-text[i]*h)+text[i+m])%q;
            if(t<0){
                t=t+q;
            }
        }
    }
}

int main(){
    string t="Deepak Ragavendra";
    string p="a";
    int q=101;
    rabin(t,p,q);
}