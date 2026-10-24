#include<iostream>
using namespace std;

int n, r;
int judge(int x){
    if(x==1) return 0;
    if(x%2==0) return 0;
    int t=0;
    for(int i=1;i*i<x;++i){
        if(x%i==0) t+=2;
        if(t==8) return 1;
    }
    return 0;
}

int main(){
    cin>> n;
    for(int i=1; i<=n; ++i){
        if(judge(i)) {
            r++;
        }
    }
    cout<< r;
}