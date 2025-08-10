#include<iostream>
#include<string>

using namespace std;

int main(){
    cout<<"Enter the real part of first part:";
    int a1;
    cin>>a1;
    cout<<"Enter the imaginary of first part:";
    int a2;
    cin>>a2;
    cout<<"Enter the real part of second part:";
    int b1;
    cin>>b1;
    cout<<"Enter the imaginary of second part:";
    int b2;
    cin>>b2;
    int s1=a1*b1+a2*b2*-1;
    int s2=a1*b2+a2*b1;
    cout<<"Output: ("<<s1<<" + "<<s2<<"i)";
    
    return 0;
}