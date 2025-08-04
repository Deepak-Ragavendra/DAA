#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<ctime>

using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    int i=low,j=mid+1,k=0;
    int temp[high - low + 1];
    while(i<=mid && j<=high){
        if(arr[j]<arr[i]) temp[k++]=arr[j++];
        else temp[k++]=arr[i++];
    }
    while(i<=mid)
        temp[k++]=arr[i++];
    while(j<=high)
        temp[k++]=arr[j++];
    for(int p= low;p<=high;p++){
        arr[p]=temp[p-low];
    }
}

void mergesort(vector<int> &arr,int low,int high){
    if(low >= high) return;
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main(){
    int num;
    vector<int> l;
    ifstream f1("page_counts.txt");
    if(f1.is_open()){
        while(f1>>num) l.push_back(num);
        f1.close();
    }
    int n=l.size();
    clock_t start=clock();
    mergesort(l,0,n-1);
    clock_t end=clock();
    cout<<"Time taken of Merge sort (20000 values): "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
    ofstream f2("out_page_counts.txt");
    for(int i=0;i<n;i++){
        f2<<l[i]<<" ";
    }
    return 0;
}