#include<iostream>
using namespace std;

int r;
int main(){
    cin>> r;
    if(r<1200) cout<< "ABC";
    else if(r<2800) cout<< "ARC";
    else cout<< "AGC";
}