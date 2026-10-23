#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<int, int> pii;
const int N= 55;
char m[N][N];
int h, w, f[N][N], black;
queue<pii> q;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

void bfs(int x, int y){
    q.push({x, y});
    f[x][y]= 0, m[x][y]= '#';
    while(!q.empty()){
        pii t= q.front();
        q.pop();
        for(int i=0; i<4;++i){
            int a= t.first+dx[i];
            int b= t.second+dy[i];
            // if(a==h && b==w) 
            if(a>=1 && b>=1 && a<=h && b<=w && m[a][b]!='#'){
                m[a][b]='#';
                f[a][b]=f[t.first][t.second]+1;
                q.push({a, b});
            } 
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(f, -1, sizeof(f));
    cin>> h>> w;
    for(int i=1; i<=h; ++i){
        for(int j=1; j<=w; ++j){
            char t;
            cin>> t;
            m[i][j]= t;
            if(t=='#') black++;
        }
    }
    bfs(1,1);
    if(f[h][w]!=-1) {
        // 总格数-开始的黑色格子数-走过的最少白格子数
        cout<< h*w-black-(f[h][w]+1);
    }
    else cout<< -1;

}