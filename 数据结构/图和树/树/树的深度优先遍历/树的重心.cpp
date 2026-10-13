#include<iostream>
#include<cstring>
using namespace std;

const int N= 100010;
int n;
// 使用链式前向星存储树
int h[N], e[N*2], nxt[N*2], idx; 
void init(){
    memset(h, -1, sizeof(h));
}
// a <-> b建立一条无向边
void add(int a, int b){
    e[idx]= b;
    nxt[idx]= h[a];
    h[a]= idx++;

    e[idx]= a;
    nxt[idx]= h[b];
    h[b]= idx++;
}

// vis[]用来标记节点是否被访问过，ans为剩余点数最大值
int vis[N], ans= INT32_MAX;

// dfs用来寻找以 u为根节点的子树总节点数
int dfs(int u){
    vis[u]= 1; //标记节点已经被访问
    int size= 0; // 记录最大子树节点数
    int sum= 1; // 记录以 u为根的节点数
    // 访问 u节点的子节点
    for(int i=h[u]; i!=-1; i=nxt[i]){
        int p= e[i]; // 下一个节点的编号
        if(vis[p]) continue; // 由于是无向边，此举是为了避免陷入死循环

        int t= dfs(p); // 得到一个子树的节点数
        size= max(size, t); // 更新最大子树的节点数
        sum+= t; // 更新以 u为根的节点数
    }
    // max(n-sum, size)剩余各个连通块中最大值
    // 删除 u 后，连通块包括：
    // 1) 各个子树，最大为 size
    // 2) u 的父节点方向，大小为 n - sum
    ans= min(ans, max(n-sum, size));
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    cin>> n;
    for(int i=1; i<n; ++i){
        int a, b;
        cin>> a>> b;
        add(a, b);
    }
    dfs(1);
    cout<< ans;
}