#include<iostream>
using namespace std;

const int N= 20000;
int n, m, cnt;
int a[N], b[N], c[N], dp[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n>> m;
    for(int i=1; i<=n; ++i){
        int x, y, s;
        cin>> x>> y>> s;
        if(s== 0){ // 处理完全背包
            cnt++;
            a[cnt]= x, b[cnt]= y, c[cnt]= 0;
        }
        else{ // 这里是把01背包和完全背包一起处理了
            if(s== -1) s= 1;
            for(int j=1; j<=s; j<<=1){
                cnt++;
                a[cnt]= x*j;
                b[cnt]= y*j;
                c[cnt]= 1;
                s-= j;
            }
            if(s){
                cnt++;
                a[cnt]= x*s;
                b[cnt]= y*s;
                c[cnt]= 1;
            }
        }
    }

    for(int i=1; i<=cnt; ++i){
        if(c[i]==0){ // 完全背包
            for(int j=a[i]; j<=m; ++j){
                dp[j]= max(dp[j], dp[j-a[i]]+b[i]);
            }
        }
        else{ // 01背包
            for(int j=m; j>=a[i]; --j){
                dp[j]= max(dp[j], dp[j-a[i]]+b[i]);
            }
        }
    }
    cout<< dp[m];

}