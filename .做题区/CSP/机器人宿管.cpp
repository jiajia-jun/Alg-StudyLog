#include<iostream>
using namespace std;

const int M= 2010;
long long a[M], n, k, m, re;

void did(long long mid){
    //memset(a, 0, sizeof(a));
    for(long long i=1; i<=m; ++i){
        a[i]= a[i-1]- (a[i-1]*k+99)/100- mid;
        if(a[i]<0) {
            a[m]= -1;
            break;
        }
    }
}

void find(long long l,long long r){
    a[0]= n;
    while(l< r){
        long long mid= (l+r)>> 1;
        did(mid);
        if(a[m]>=0){
            re= max(re, mid);
            l= mid+1;
        }
        else r= mid; 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n >>k >>m;
    find(1, n/m);
    cout<< re;
}