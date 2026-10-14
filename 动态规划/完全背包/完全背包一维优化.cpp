#include<iostream>
using namespace std;

const int N= 1010;
int dp[N], n, volume;
int v[N], w[N];

int main(){
    cin>> n>> volume;
    for(int i=1; i<=n; ++i){
        cin>> v[i]>> w[i];
        for(int j=v[i]; j<= volume; ++j){ //正向遍历
            dp[j]= max(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    cout<< dp[volume];
}