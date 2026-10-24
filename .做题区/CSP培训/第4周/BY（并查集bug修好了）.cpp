#include<iostream>
#include<set>
using namespace std;

typedef pair<int, int> pii;
const int N= 110;
char a[N][N]; //存地图
pii p[N][N]; //p[i][j]：表示a[i][j]的祖先
set<pii> st; //记录最后的连通块数目
int n, m;

pii find(int x, int y){
    // 根节点：p[x][y].first==x && p[x][y].second==y
    // 未遍历到根节点
    if(p[x][y].first!=x || p[x][y].second!= y){
        return p[x][y]= find(p[x][y].first, p[x][y].second);
    }
    return p[x][y];
}

void merge(int a, int b, int c, int d){
    pii t= find(a, b); //找到a[i][j]的祖宗
    p[t.first][t.second]= find(c, d); //合并两个集合
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n>> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            char c;
            cin>> c;
            a[i][j]= c;
            p[i][j].first=i, p[i][j].second=j;
        }
    }

    // 并查集是无方向性的，对称位置会被邻居覆盖，
    // 所以只要四个方向：右，下，右下，右上
    int dx[5]={0,-1, 0, 1, -1};
    int dy[5]={0, 0, 1, 1, 1};
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(a[i][j]=='.') continue;
            for(int k=1; k<=4; ++k){
                int x=i+dx[k], y=j+dy[k];
                if(a[x][y]=='W'){
                    merge(i, j, x, y);
                }
            }
        }
    }
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(a[i][j]== 'W'){
                //cout<<find(i, j).first<<' '<<find(i, j).second<<'\n';
                st.insert(find(i, j));
            }
        }
    }
    cout<<st.size();
}