#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <numeric>
using namespace std;

void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> left(arr.begin()+low,arr.begin()+mid+1);
    vector<int> right(arr.begin()+mid+1,arr.begin()+high+1);
    int i=0,j=0,k=low;
    while(i<left.size() && j<right.size()){
        if(left[i]>=right[j]){
            arr[k++]=left[i++];
        }
        else{
            arr[k++]=right[j++];
        }
    }
    while(i<left.size()){
        arr[k++]=left[i++];
    }
    while(j<right.size()){
        arr[k++]=right[j++];
    }
}
void mergesort(vector<int> &arr,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    std::vector<int> sdata(100);
    iota(sdata.begin(), sdata.end(), 0);
    std::vector<int> given(sdata.begin(), sdata.end());
    int n = given.size();
    vector<int> fib = {1, 2};
    clock_t start=clock();
    while(true){
        int next = fib[fib.size()-1] + fib[fib.size()-2];
        if(next >= n) break;
        fib.push_back(next);
    }
    vector<int> arr;
    for(int i = 0; i < fib.size(); i++){
        arr.push_back(given[fib[i]]);
    }
    mergesort(arr, 0, arr.size() - 1);
    for(int i = 0; i < fib.size(); i++){
        given[fib[i]] = arr[i];
    }

    for(int i = 0; i < n; i++){
        cout << given[i] << " ";
    }
    cout << "\n";
    clock_t end=clock();
    cout<<"Time taken= "<<(double)(end-start)/CLOCKS_PER_SEC;
    return 0;
}
