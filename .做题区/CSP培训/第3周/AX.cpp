#include<iostream>
using namespace std;

const int N= 10010;
int a[N], n, r;
int cnt;

int did(int x){
    int c= 0;
    while(x%2!=1){
        x/=2;
        c++;
    }
    return c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    for(int i=1; i<=n; ++i){
        cin>> a[i];
        if(a[i]%2==1) cnt++;
        else r+= did(a[i]);
    }
    if(cnt==n) {
        cout<< 0;
        return 0;
    }
    cout<< r;
}