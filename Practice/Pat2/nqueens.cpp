#include<iostream>
#include<vector>
using namespace std;

void place(int i,vector<int> cur,vector<int> col,vector<int> left,vector<int> right,vector<vector<int>> &res){
    int n=col.size();
    if(i==n){
        res.push_back(cur);
        return;
    }
    for(int j=0;j<n;j++){
        if(col[j] || left[i+j] || right[i-j+n-1]){
            continue;
        }
        col[j]=1;
        left[j+i]=1;
        right[i-j+n-1]=1;
        cur.push_back(j+1);

        place(i+1,cur,col,left,right,res);

        col[j]=0;
        left[j+i]=0;
        right[i-j+n-1]=0;
        cur.pop_back();
    }
}

vector<vector<int>> queens(int n){
    vector<int> cur;
    vector<int> col(n,0);
    vector<int> left(n*2,0);
    vector<int> right(n*2,0);
    vector<vector<int>> res;
    place(0,cur,col,left,right,res);
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> p=queens(n);
    for(auto &i:p){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}