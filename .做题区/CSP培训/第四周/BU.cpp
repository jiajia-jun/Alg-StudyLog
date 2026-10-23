#include<iostream>
#include<cstring>
using namespace std;

const int N= 2010;
int n, x, y;
int dp[N][N], r[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n>> x>> y;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            // min(直达，经过额外的一条路)
            dp[i][j]= min(abs(j-i), 
            min(abs(x-i)+1+abs(y-j), abs(y-i)+1+abs(x-j)));
            r[dp[i][j]]++;
        }
    }
    // 同个路径会算两次
    for(int i=1; i<=n-2; ++i){
        cout<< r[i]/2<< '\n';
    }
    cout<< r[n-1]/2;
}