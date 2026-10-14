#include<iostream>
using namespace std;

const int N= 1010;
int dp[N][N], nn, vv; // nn物品数目，vv背包大小
int v[N], w[N];// v体积， w价值

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> nn>> vv;
    for(int i=1; i<=nn; ++i){
        cin>> v[i]>> w[i];
    }

    for(int i=1; i<=nn; ++i){
        for(int j=1; j<=vv; ++j){
            if(v[i]> j) dp[i][j]= dp[i-1][j];
            else dp[i][j]= max(dp[i-1][j-v[i]]+w[i], dp[i-1][j]);
        }
    }
    cout<< dp[nn][vv];
}