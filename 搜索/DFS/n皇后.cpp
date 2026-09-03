#include<iostream>

using namespace std;

const int N= 110;

char q[N][N];

int c[N], dg[N*2+10], udg[N*2+10], n;

// i代表行数，按行分层
void dfs(int i){
    if(i> n){
        for(int x=1; x<=n; ++x){
            for(int y=1; y<=n; ++y){
                cout<<q[x][y];
            }
            cout<<'\n';
        }
        cout<<'\n';
        return;
    }
    // 枚举列数，填入一行的每个列
    for(int j=1; j<=n; ++j){
        if(c[j] || dg[i+j] || udg[i-j+n]) continue;
        q[i][j]= 'Q';
        c[j]= dg[i+j]= udg[i-j+n]= 1;
        dfs(i+1);
        q[i][j]= '.';
        c[j]= dg[i+j]= udg[i-j+n]= 0;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    for(int x=1; x<=n; ++x){
        for(int y=1; y<=n; ++y){
            q[x][y]= '.';
        }
    }

    dfs(1);
    return 0;
}