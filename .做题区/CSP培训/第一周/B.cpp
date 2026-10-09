#include<iostream>
using namespace std;

const int N= 210;
int a[N], r, n, f;

void did(){
    while(!f){
        for(int i=0; i<n; ++i){
            if(a[i]%2!=0) {
                f= 1;
                break;
            }
            a[i] /=2;
        }
        if(!f) r++;
    }
}

int main(){
    cin>> n;
    for(int i=0; i<n; ++i) cin>>a[i];
    did();
    cout<< r;
}