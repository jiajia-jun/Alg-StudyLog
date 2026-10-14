#include<iostream>
using namespace std;

const int N= 1010;
int dp[N][N], n, volume;
int v[N], w[N];

int main(){
    cin>> n>> volume;
    for(int i=1; i<=n; ++i){
        cin>> v[i]>> w[i];
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=volume; ++j){
            if(v[i]> j) dp[i][j]= dp[i-1][j];
            else dp[i][j]= max(dp[i-1][j], dp[i][j-v[i]]+w[i]);
        }
    }
    cout<< dp[n][volume];
}