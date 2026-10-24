#include<iostream>
using namespace std;

long long n, m;
long long cac(){
    long long a=0, b=0;
    if(m<2) a= m; else a= m-2;
    if(n<2) b= n; else b= n-2;
    return a*b;
}

int main(){
    cin>> n>> m;
    cout<< cac();
}