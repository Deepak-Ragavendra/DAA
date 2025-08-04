#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

void insertion_sort(vector<int> &arr,int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int num;
    vector<int> l;
    ifstream f1("book_thickness1.txt");
    if(f1.is_open()){
        while(f1>>num) l.push_back(num);
        f1.close(); 
    }
    else{
        cout<<"Cannot open file!!"<<endl;
    }
    int n=l.size();
    clock_t start=clock();
    insertion_sort(l,n);
    clock_t end=clock();
    cout<<"Time taken of Insertion sort :"<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
    ofstream f2("out_book_thickness1.txt");
    for(int i=0;i<n;i++){
        f2<<l[i]<<" ";
    }
    f2.close();
    return 0;
}