#include<iostream>
#include<set>
using namespace std;

typedef pair<int, int> pii;
const int N= 110;
int a[N][N]; //存地图
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
            a[i][j]= c-'0';
            p[i][j].first=i, p[i][j].second=j;
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(a[i][j]==0) continue;
            if(a[i][j+1]!=0){
                merge(i, j, i, j+1);
            }
            if(a[i+1][j]!=0){
                merge(i, j, i+1, j);
            }
        }
    }
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(a[i][j] > 0){
                st.insert(find(i, j));
            }
        }
    }
    cout<<st.size();
}