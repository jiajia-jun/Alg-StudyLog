#include<iostream>
using namespace std;

const int N= 100010;
int v[N], s[N], prim[N], q;

void did(){
    for(int i=2; i<= 100000; ++i){
        if(!v[i]) {
            prim[i]= 1;
            for(long long j=i*2; j<=100000; j+=i){
                v[j]= 1;
            }
        }
    }
    for(int i=1; i<= 100000; ++i){
        s[i]= s[i-1]+ (prim[i]&&prim[(i+1)/2]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> q;
    did();
    while(q--){
        int l, r;
        cin>> l>> r;
        cout<< s[r]- s[l-1] << '\n';
    }
}
