#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void merge(vector<int> &arr,int low,int mid,int high){
    int i=low,j=mid+1,k=0;
    int temp[high-low+1];
    while(i<=mid && j<=high){
        if(arr[i]>arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    for(int t=low;t<=high;t++){
        arr[t]=temp[t-low];
    }
}

void mergesort(vector<int> &arr,int low,int high){
    if(low>=high) return;
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void find(vector<int> &arr,int low,int high){
    vector<int> odd;
    for(int i=0;i<arr.size();i++){
        if((i+1)%2!=0){
            odd.push_back(arr[i]);
        }
    }
    mergesort(odd,low,high);
    int k=0;
    for(int i=0;i<odd.size();i++){
        arr[k]=odd[i];
        k+=2;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    int k;
    for(int i=0;i<n;i++){
        cin>>k;
        arr.push_back(k);
    }
    clock_t start=clock();
    find(arr,0,n-1);
    clock_t end=clock();
    cout<<"Time taken: "<<(double)(end-start)/CLOCKS_PER_SEC;
}