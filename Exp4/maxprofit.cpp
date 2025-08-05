#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void mergesort(vector<int> arr,int low,int high,vector<int> &res){
    if(low>=high) {
        if(arr[low]>0){
            res.push_back(arr[low]);
        }
        return;
    };
    int mid=(low+high)/2;
    mergesort(arr,low,mid,res);
    mergesort(arr,mid+1,high,res);
}

int main(){
    vector<int> arr;
    vector<int> res;
    int n;
    cin>>n;
    int p;
    for(int i=0;i<n;i++){
        cin>>p;
        arr.push_back(p);
    }
    clock_t start=clock();
    mergesort(arr,0,n-1,res);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    clock_t end=clock();
    cout<<"\nTime : "<<(double)(end-start)/CLOCKS_PER_SEC;
    return 0;
}