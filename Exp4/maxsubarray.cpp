#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Find{
    public:
    int sum,leftindex,rightindex;
};

Find merge(vector<int> arr,int low,int mid,int high){
    int sum=0,leftsum=INT_MIN,rightsum=INT_MIN,leftindex,rightindex;
    for(int i=mid;i>=low;i--){
        sum+=arr[i];
        if(leftsum<sum){
            leftsum=sum;
            leftindex=i;
        }
    }
    sum=0;
    for(int i=mid+1;i<=high;i++){
        sum+=arr[i];
        if(rightsum<sum){
            rightsum=sum;
            rightindex=i;
        }
    }
    sum=leftsum+rightsum;
    return {sum,leftindex,rightindex};
}

Find mergesort(vector<int> arr,int low,int high){
    if(low>=high) return {arr[low]};
    int mid=(low+high)/2;
    Find l=mergesort(arr,low,mid);
    Find r=mergesort(arr,mid+1,high);
    Find c=merge(arr,low,mid,high);
    if(l.sum>=r.sum && l.sum>=c.sum){
        return l;
    }
    else if(r.sum>l.sum && r.sum>c.sum){
        return r;
    }
    else{
        return c;
    }
}

int main(){
    vector<int> arr;
    int n;
    cin>>n;
    int p;
    for(int i=0;i<n;i++){
        cin>>p;
        arr.push_back(p);
    }
    clock_t start=clock();
    Find res=mergesort(arr,0,n-1);
    for(int i=res.leftindex;i<=res.rightindex;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nSum : "<<res.sum;
    clock_t end=clock();
    cout<<"\nTime : "<<(double)(end-start)/CLOCKS_PER_SEC;
    return 0;
}