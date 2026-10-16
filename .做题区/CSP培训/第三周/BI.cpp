#include<iostream>
using namespace std;

const int N= 55;
int a[N], n, r;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    for(int i=1; i<=n; ++i){
        cin>> a[i];
    }
    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            r+=a[i]*a[j];
        }
    }
    cout<< r;
}