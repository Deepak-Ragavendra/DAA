#include<iostream>
#include<fstream>
#include<unordered_set>
#include<ctime>
#include<cstdlib>

using namespace std;

int main(){
    srand(time(0));
    unordered_set<int> nums;
    int c=20000;
    while(nums.size()<c){
        int num=rand()%50000+1;
        nums.insert(num);
    }
    ofstream f1("page_counts.txt");
    for(int num:nums){
        f1<<num<<endl;
    }
    f1.close();
    return 0;
}