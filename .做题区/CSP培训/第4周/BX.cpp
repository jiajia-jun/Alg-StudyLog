#include<iostream>
using namespace std;

typedef long long ll;
const ll N= 410;
// f[i][j]: i城市到j城市的路程
ll f[N][N], n, m, r;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin>> n>> m;
    for(ll i=1; i<=n; ++i){
        for(ll j=1; j<=n; ++j){
            if(i==j) f[i][i]= 0;
            else f[i][j]= 1e10;
        }
    }
    for(ll i=1 ;i<=m; ++i){
        ll a, b, c;
        cin>> a>> b>> c;
        f[a][b]= c;
    }
    for(ll k=1; k<=n; ++k){
        for(ll s=1; s<=n; ++s){
            for(ll t=1; t<=n; ++t){
                // min(经过k城到达, 不经过k城直接到达)
                f[s][t]=min(f[s][t], f[s][k]+f[k][t]);
            }
        }
        for(ll s=1; s<=n; ++s){
            for(ll t=1; t<=n; ++t){
                if(f[s][t]!=1e10) r+=f[s][t];
            }
        }
    }
    cout<< r;
}