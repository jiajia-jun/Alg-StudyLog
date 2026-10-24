#include<iostream>
using namespace std;

const int N= 100010;
int a[N], b[N], n, r;

int main(){
    cin>> n;
    for(int i=1; i<=n; ++i) cin>> a[i];
    for(int i=1; i<=n; ++i) cin>> b[i];
    for(int i=1; i<=n; ++i){
        r+= a[i]*b[i];
    }
    if(!r) cout<<"Yes";
    else cout<<"No";
}