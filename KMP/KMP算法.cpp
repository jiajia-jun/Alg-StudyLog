#include<iostream>
using namespace std;

const int N= 100010, M= 1000010;

char p[N], s[M];

int nxt[N], n, m;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    for(int i=1; i<=n; ++i) cin>> p[i];
    cin>> m;
    for(int i=1; i<=m; ++i) cin>> s[i];

    // 计算 nxt[]数组
    // j表示的是：当前已经匹配成功的长度
    // nxt[j]表示是：p[1,j]串中前缀和后缀相同的最大长度
    for(int i=2, j=0; i<=n; ++i){
        while(j!=0 && p[i] != p[j+1]){
            j= nxt[j];
        }
        if(p[i] == p[j+1]) j++;
        nxt[i] = j;
    }

    // 进行匹配
    int l=0, r=0;
    for(int i=1, j=0; i<=m; ++i){
        while(j!=0 && s[i]!= p[j+1]){
            j = nxt[j];
        }
        if(s[i]== p[j+1]) j++;
        if(j == n) {
            l= i-n, r= i-1; //0-base下标
            break;
        }
    }
    cout<< l <<' '<< r;
}