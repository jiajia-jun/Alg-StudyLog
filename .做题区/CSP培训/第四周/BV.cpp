#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N= 200010;
int h[N], e[2*N], nxt[2*N], vis[N], idx;
// pt[i]：i号房间指向的房号
int n, m, pt[N], okk;

void add(int a, int b){
    e[idx]= b, nxt[idx]= h[a], h[a]= idx++;
    e[idx]= a, nxt[idx]= h[b], h[b]= idx++;
}

void bfs(int x){
    queue<int> q;
    q.push(x);
    vis[x]= 1;
    while(!q.empty()){
        int t= q.front();
        q.pop();
        for(int i=h[t]; i!=-1; i=nxt[i]){
            int a= e[i];
            if(vis[a]) continue;
            q.push(a);
            vis[a]= 1, pt[a]= t;
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
    bfs(1);
    for(int i=1; i<=n; ++i){
        if(vis[i]!=1){
            cout<<"No";
            return 0;
        }
    }
    cout<< "Yes\n";
    for(int i=2; i<=n; ++i) cout<< pt[i]<< '\n';
}