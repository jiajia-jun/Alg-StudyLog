#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const long long N= 100010;
// 链式前向星
long long h[N], e[2*N], nxt[2*N], w[2*N], idx, n;
queue<long long> q;
// color标记颜色，vis标记是否访问，f[i]标记根节点到i节点的距离
long long color[N], vis[N], f[N];

void add(long long u, long long v, long long wt){
    w[idx]= wt;
    e[idx]= v, nxt[idx]= h[u], h[u]= idx++;

    w[idx]= wt;
    e[idx]= u, nxt[idx]= h[v], h[v]= idx++;
}

void bfs(long long x){
    q.push(x);
    f[x]= 0, color[x]= 0, vis[x]= 1;
    while(!q.empty()){
        long long t=q.front();
        q.pop();
        
        for(long long i=h[t];i!=-1;i=nxt[i]){
            long long a= e[i];
            if(vis[a]) continue;
            q.push(a), vis[a]= 1;
            // 距离为偶数为0，奇数为1
            f[a]= f[t]+ w[i];
            color[a]= f[a]%2;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof(h));
    cin>> n;
    for(long long i=1; i<=n-1; ++i){
        long long u, v, wt;
        cin>> u>> v>> wt;
        add(u, v, wt);
    }
    bfs(1);
    for(long long i=1; i<=n; ++i){
        cout<< color[i]<< '\n';
    }

}