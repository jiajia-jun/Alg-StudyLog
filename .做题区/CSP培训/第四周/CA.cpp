#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int, int> pii;

const int N= 410;
int g[N][N], f[N][N], vis[N][N];
int n, m, x, y;
queue<pii> q;

int dx[9]={0,2,-2,-1,1,-1,1,2,-2};
int dy[9]={0,1,1,2,2,-2,-2,-1,-1};


void bfs(int x, int y){
    f[x][y]= 0;
    q.push({x, y});
    while(!q.empty()){
        pii t= q.front();
        q.pop();
        for(int i=1; i<=8; ++i){
            int a= t.first+dx[i];
            int b= t.second+dy[i];
            if(a>=1 && b>=1 && a<=n && b<=m && f[a][b]==-1){
                q.push({a, b});
                f[a][b]= f[t.first][t.second]+1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(f, -1, sizeof(f));
    cin>> n>> m>> x>> y;
    bfs(x, y);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cout<< f[i][j]<<' ';
        }
        cout<<'\n';
    }
}