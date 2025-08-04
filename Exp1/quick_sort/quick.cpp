#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<ctime>

using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low, j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high) i++;
        while(arr[j] > pivot && j >= low) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(vector<int> &arr, int low, int high){
    if(low>=high) return;
    int p=partition(arr,low,high);
    quicksort(arr,low,p-1);
    quicksort(arr,p+1,high);
}

int main(){
    int num;
    vector<int> l;
    ifstream f1("packages_weights.txt");
    if(f1.is_open()){
        while(f1>>num) l.push_back(num);
        f1.close();
    }
    int n=l.size();
    clock_t start=clock();
    quicksort(l,0,n-1);
    clock_t end=clock();
    cout<<"Time taken of Quick Sort(20000 values): "<<(double)(end-start)/CLOCKS_PER_SEC;
    ofstream f2("out_packages_weights.txt");
    for(int i=0;i<n;i++){
        f2<<l[i]<<" ";
    }
    return 0;
}