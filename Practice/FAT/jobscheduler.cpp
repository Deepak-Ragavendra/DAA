#include<iostream>
#include<vector>

using namespace std;

struct event{
    int profit,time,id;
};

void merge(vector<event> &arr,int low,int mid,int high){
    int i=low,j=mid+1,k=0;
    vector<event> temp;
    while(i<=mid && j<=high){
        if(arr[i].profit<arr[j].profit){
            temp[k].id=arr[j].id;
            temp[k].time=arr[j].time;
            temp[k++].profit=arr[j++].profit;
        }
        else{
            temp[k].id=arr[i].id;
            temp[k].time=arr[i].time;
            temp[k++].profit=arr[i++].profit;
        }
    }
    while(i<=mid){
        temp[k].id=arr[i].id;
        temp[k].time=arr[i].time;
        temp[k++].profit=arr[i++].profit;
    }
    while(j<=high){
        temp[k].id=arr[j].id;
        temp[k].time=arr[j].time;
        temp[k++].profit=arr[j++].profit;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void mergesort(vector<event> &arr,int low,int high){
    if(low>=high) return;
    int mid=low+(high-low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main(){
    vector<event> arr;
    int n;
    cin>>n;
    cout<<"Input like profit,timeline,id";
    for(int i=0;i<n;i++){
        cin>>arr[i].profit>>arr[i].time>>arr[i].id;
    }
    mergesort(arr,0,n-1);
    int maxtime=INT_MIN;
    for(int i=0;i<n;i++){
        maxtime=max(maxtime,arr[i].time);
    }
    vector<int> res(maxtime);
    for(int i=n-1;i>=0;i--){
        
    }
    return 0;
}