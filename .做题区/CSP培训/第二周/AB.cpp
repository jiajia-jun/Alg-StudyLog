#include<iostream>
using namespace std;

int a, b;
char s[100];

bool judge(){
    for(int i=1; i<=a+b+1; ++i){
        if(i!=a+1 && !(s[i]>=48 && s[i]<=57)) return false;
        if(i==a+1 && s[i]!='-') return false;
    }
    return true;
}

int main(){
    cin>> a>> b;
    for(int i=1; i<=a+b+1; ++i){
        cin>> s[i];
    }
    if(judge()) cout<<"Yes";
    else cout<<"No";
}