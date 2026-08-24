#include<iostream>
using namespace std;

const int N= 10010;
int a[N][N], d[N][N];

// 配合前缀和，可以让修改可以形成一个平面范围的影响
// 你可以自己画一个点阵，左上角为原点
// 然后这段代码配合最后的前缀和的几何意义就是：
// 以坐标为左上角的点的矩形，区域内的所有点都加上c
void dif(int x1, int y1, int x2, int y2, int c){
    d[x1][y1]+= c;
    d[x1][y2+1]-= c;
    d[x2+1][y1]-= c;
    d[x2+1][y2+1]+= c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin>>n >>m>> q;

    // 从 1 开始存可以免去繁杂的边界问题
    for(int i=1;i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin>>a[i][j];
        }
    }
    
    // 这里并不是直接采用公式构造，要注意了
    // 这种写法和使用公式构造差分数组的效果是一样的
    // 差分公式：d[i][j] = a[i][j] - a[i-1][j] - a[i][j-1] + a[i-1][j-1]
    for(int i=1;i<=n; ++i){
        for(int j=1; j<=m; ++j){
            dif(i, j, i, j, a[i][j]); 
        }
    }

    // 指定子矩阵区域加上c
    while(q--){
        int x1,y1,x2,y2,c;
        cin>> x1>> y1>> x2>> y2 >>c;
        dif(x1, y1, x2, y2, c);
    }
    for(int i=1;i<=n; ++i){
        for(int j=1; j<=m; ++j){
            d[i][j]+= d[i-1][j]+ d[i][j-1]- d[i-1][j-1]; // 前缀和
        }
    }
    
    for(int i=1;i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cout<< d[i][j] <<' ';
        }
        cout<<'\n';
    }
}