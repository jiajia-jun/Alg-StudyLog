#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N= 55;
int n, m, r, vis[N];
int h[N], e[2*N], nxt[2*N], idx;
queue<int> q;

void add(int a, int b){
    e[idx]=a, nxt[idx]=h[b], h[b]=idx++;
    e[idx]=b, nxt[idx]=h[a], h[a]=idx++;
}

void bfs(int x,int ban){
    q.push(x);
    vis[x]=1;
    while(!q.empty()){
        int t= q.front();
        q.pop();
        for(int i=h[t]; i!=-1; i=nxt[i]){
            if(i==ban || i==ban+1){
                continue;
            }
            int a= e[i];
            if(vis[a]) continue;
            vis[a]= 1;
            q.push(a);
        }
    }
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
    // 依次去除每一个边后，是否可以遍历全部节点
    for(int i=0; i<idx; i+=2){
        bfs(1, i); 
        for(int j=1; j<=n; ++j){
            if(!vis[j]) {
                r++;
                break;
            }
        }
        memset(vis, 0, sizeof(vis));
    }
    cout<< r;
}