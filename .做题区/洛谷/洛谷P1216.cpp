#include<iostream>
#include<cstring>
using namespace std;

const int N=1010;
int n, a[N][N], f[N][N];

int dfs(int x, int y){
    if(f[x][y]!=-1) return f[x][y];
    if(x==n-1) f[x][y]=a[x][y];
    else{
        f[x][y]=a[x][y]+max(dfs(x+1,y), dfs(x+1,y+1));
    }
    return f[x][y];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(f, -1, sizeof(f));
    cin>> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<i+1; ++j){
            cin>> a[i][j];
        }
    }
    cout<<dfs(0,0);
}