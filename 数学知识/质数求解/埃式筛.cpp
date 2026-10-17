#include<iostream>
using namespace std;

const int N= 100010;
int v[N], s[N], prim[N], q, n;

void did(int n){

//-------------------埃氏筛---------------------------
    for(int i=2; i<= n; ++i){
        if(!v[i]) {
            prim[i]= 1;
            for(long long j = 1LL*i*i; j<=n; j+=i){ // 质数的倍数一定是合数
                v[j]= 1;
            }
        }
    }

    for(int i=1; i<= n; ++i){
        s[i]= s[i-1]+ prim[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n>> q;
    did(n);
    while(q--){
        int l, r;
        cin>> l>> r;
        cout<< s[r]- s[l-1] << '\n';
    }
}
