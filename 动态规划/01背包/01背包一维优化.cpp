#include<iostream>
using namespace std;

const int N= 1010;
int dp[N], nn, vv; // nn物品数目，vv背包大小
int v[N], w[N];// v体积， w价值

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> nn>> vv;
    for(int i=1; i<=nn; ++i){
        cin>> v[i]>> w[i];
        for(int j=vv; j>=v[i]; j--){
            dp[j]= max(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    cout<< dp[vv];
}