#include<iostream>
#include<cstring>
using namespace std;

const int N= 100;
int h[N], e[2*N], nxt[2*N], idx, vis[N];
int n, m, r;

void add(int a, int b){
    e[idx]= b, nxt[idx]= h[a], h[a]= idx++;
    e[idx]= a, nxt[idx]= h[b], h[b]= idx++;
}

void dfs(int x, int cnt){
    vis[x]= 1;
    if(cnt == n){   // 已经遍历完所有节点
        r++, vis[x]= 0;
        return;
    }
    for(int i = h[x]; i != -1; i = nxt[i]){
        int y = e[i];
        if(vis[y]) continue;
        dfs(y, cnt+1);
    }
    vis[x]= 0;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof(h));
    cin>> n>> m;
    for(int i=1; i<=m; ++i){
        int a, b;
        cin>> a>> b;
        add(a, b);
    }
    dfs(1, 1);
    cout<< r;
}