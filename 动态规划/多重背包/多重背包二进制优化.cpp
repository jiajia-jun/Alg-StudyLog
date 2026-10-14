#include<iostream>
using namespace std;

const int N= 20000;// 二进制拆分后，物品数量会变成SUM(⌊log2(si)⌋+1)
int dp[N], v[N], w[N];
int n, volume;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n>> volume;
    // 二进制优化
    int cnt= 0;
    for(int i=1; i<=n; ++i){
        int a, b, s;
        cin>> a>> b>> s;
        for(int j=1; j<=s; j<<= 1){
            cnt++;
            v[cnt]= a*j;
            w[cnt]= b*j;
            s-= j;
        }
        if(s){
            cnt++;
            v[cnt]= a*s;
            w[cnt]= b*s;
        }
    }
    
    // 转化为01背包问题
    for(int i=1; i<= cnt; ++i){
        for(int j= volume; j>=v[i]; --j){
            dp[j]= max(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    cout<< dp[volume];
}