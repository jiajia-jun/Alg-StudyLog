#include<iostream>
#include<queue>
using namespace std;

const int N= 60;
typedef pair<int, int> pii;

char m[N][N];
int f[N][N];
int R, C, sy, sx, gy, gx;
queue<pii> q;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

int bfs(int x, int y){
    f[x][y] = 0, m[x][y] = '#';
    q.push({x, y});
    while(!q.empty()){
        pii t= q.front();
        q.pop();
        for(int i=0; i<4;++i){
            int a= t.first+dx[i];
            int b= t.second+dy[i];
            if(a>=1&&b>=1&&a<=R&&b<=C&&m[a][b]!='#'){
                m[a][b]='#';
                f[a][b]=f[t.first][t.second]+1;
                q.push({a, b});
            }
        }
    }
    return f[gy][gx];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> R>> C;
    cin>> sy>> sx>> gy>> gx;
    for(int i=1; i<=R; ++i){
        for(int j=1; j<=C; ++j){
            cin>> m[i][j];
        }
    }
    
    cout<< bfs(sy, sx)<< '\n';

}
