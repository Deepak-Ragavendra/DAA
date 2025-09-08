#include<iostream>
#include<vector>

using namespace std;

void printOptimal(vector<vector<int>>& s,int i,int j){
    if(i==j){
        cout<<"A"<<i;
    }
    else{
        cout<<"(";
        printOptimal(s,i,s[i][j]);
        printOptimal(s,s[i][j]+1,j);
        cout<<")";
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    vector<vector<long long>> m(n,vector<long long>(n,0));
    vector<vector<int>> s(n,vector<int>(n,0));
    for(int L=2;L<n;L++){
        for(int i=1;i<n-L+1;i++){
            int j=i+L-1;
            m[i][j]=LLONG_MAX;
            for(int k=i;k<j;k++){
                long long q=m[i][k]+m[k+1][j]+(long long)p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    cout<<"Output:"<<endl;
    cout<<m[1][n-1]<<endl;
    printOptimal(s,1,n-1);
    cout<<endl;
    return 0;
}
