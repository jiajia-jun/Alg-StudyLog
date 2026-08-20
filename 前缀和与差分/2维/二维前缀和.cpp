#include<iostream>
using namespace std;

const int N= 1010;
int a[N][N]={0}, s[N][N]={0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin>>n >>m>> q;

    //从 1 开始存可以免去繁杂的边界问题
    for(int i=1;i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin>>a[i][j];
        }
    }
    

    for(int i=1;i<=n; ++i){
        for(int j=1; j<=m; ++j){
            // 注意，这里是点阵，所以是这样计算的（画一个格子点图会更加好理解的😋）
            s[i][j]= s[i-1][j]+ s[i][j-1]+ a[i][j]-s[i-1][j-1];
        }
    }

    while(q--){
        // 均为1-base下的索引坐标
        int x1, y1, x2, y2;
        cin>> x1>> y1>> x2>> y2;
        cout<< s[x2][y2]- s[x1-1][y2]- s[x2][y1-1]+ s[x1-1][y1-1]<<'\n';
    }
    

}