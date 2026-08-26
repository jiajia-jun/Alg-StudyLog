#include<iostream>
using namespace std;

const int N= 100010;

char s[N];
int nxt[N], n;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    for(int i=1; i<=n; ++i) cin>> s[i];

    // j表示的是：当前已经匹配成功的长度（初始化为0）
    // nxt[j]表示是：s[1,j]串中前缀和后缀相同的最大长度
    int re=0;
    for(int i=2, j=0; i<=n; ++i){
        while(j!=0 && s[i] != s[j+1]){
            j= nxt[j];
        }
        if(s[i] == s[j+1]) j++;
        nxt[i] = j;
        re = max(re, j);
    }
    cout<< re <<'\n';
}