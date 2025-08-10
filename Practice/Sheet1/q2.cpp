#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cout<<"Enter the length of the array of integers:";
    cin>>n;
    vector<int> arr;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        arr.push_back(num);
    }
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    cout<<"The maximum integer in the array is "<<max;
    return 0;
}