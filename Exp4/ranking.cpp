#include<iostream>
#include<vector>

using namespace std;

void find(vector<int> s,vector<int> final,int *count,int low,int high){
    if(low>=high){
        if(s[low]!=final[low]){
            *count+=1;
        }
        return;
    }
    int mid=(low+high)/2;
    find(s,final,count,low,mid);
    find(s,final,count,mid+1,high);
    
}

int main(){
    vector<int> s={101,102,103};
    vector<int> final={102,103,101};
    clock_t start=clock();
    int count=0;
    find(s,final,&count,0,s.size()-1);
    clock_t end=clock();
    cout<<count;
    cout<<"\nTime taken : "<<(double)(end-start)/CLOCKS_PER_SEC;
}

