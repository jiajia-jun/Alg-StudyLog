#include<iostream>
using namespace std;

int a, b, c, n;
int main(){
    cin>> n>> a>> b;
    int tar= a+b;
    for(int i=1; i<=n; ++i){
        cin>> c;
        if(c== tar) cout<< i;
    }
}