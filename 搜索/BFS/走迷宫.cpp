#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;
const int N= 110;

// 从左往右分别代表上下左右
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

int q[N][N], n, m;
pii pre[N][N]; // 记录每一个点的先前点
queue<pii> pt;

// x, y代表起始点
void bfs(int x, int y){
    // 记录当前的点为不可走了
    q[x][y]= 1;
    pt.push({x, y});

    while(!pt.empty()){
        // 从队头取出点
        pii p= pt.front();
        pt.pop();
        // 遍历每个点上下左右的方向
        for(int i=0; i<4; ++i){
            // 周围点的坐标
            int a= p.first+ dx[i];
            int b= p.second+ dy[i];
            // 周围方向的点在范围内且可走
            if(a>0 && b>0 && a<=n && b<=m && q[a][b]== 0){
                q[a][b]= 1;
                pre[a][b]= p;
                pt.push({a, b});
            }
        }
    }
}

// 打印路径
// x, y表示目标点
void print_path(int x, int y) {
    // 递归法输出
    // if(x==0 && y==0) return;  // 终止条件
    // print_path(pre[x][y].first, pre[x][y].second);
    // cout << x << ' ' << y << '\n';

    vector<pii> path;
    while(x!= 0 && y!= 0){
        path.push_back({x, y});
        // 这里注意要加一个临时变量 t来代表 x，
        // 不然修改 y的时候传入的就是已经修改好的 x了
        int t= x;
        x= pre[t][y].first;
        y= pre[t][y].second;
    }

    reverse(path.begin(), path.end());
    for(auto &m: path){
        cout<< m.first <<' ' << m.second<< '\n';
    }
    cout<<path.size() <<'\n';

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>> n>> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin>> q[i][j];
        }
    }
    bfs(1, 1);
    print_path(n, m);
}