#include<iostream>
using namespace std;

const int N= 100010;
int v[N], prim[N], n, cnt;

// 找出小于等于n的所有质数
void did(int n){ 
//-------------------线性筛---------------------------
    for (int i = 2; i <= n; i++) {
        if (!v[i]) prim[++cnt] = i; // 收集质数

         // 核心：让每个合数，都只被它的“最小质因子”筛掉，且只筛一次
        for (int j = 1; 1ll*i*prim[j] <= n; ++j) {
            v[i*prim[j]] = 1; // 筛合数
            if (i%prim[j] == 0) break; // 
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    did(n);

    for(int i=1; i<=cnt; ++i){
        printf("%d ", prim[i]);
    }
}
