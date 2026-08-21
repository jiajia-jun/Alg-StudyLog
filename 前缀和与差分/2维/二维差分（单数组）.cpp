#include<iostream>
using namespace std;

const int N = 10010;
int d[N][N];  // 一个数组

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    // 读入原始矩阵到 d
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> d[i][j];

    // 原地构建差分（从右下到左上），这里就是和原来两个的区别
    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            // 此时 d[i-1][j] 和 d[i][j-1] 仍是原始值
            d[i][j] = d[i][j] - d[i-1][j] - d[i][j-1] + d[i-1][j-1]; // 差分公式还是这个

        }
    }

    // 区间加法操作（直接修改差分）
    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        d[x1][y1] += c;
        d[x1][y2 + 1] -= c;
        d[x2 + 1][y1] -= c;
        d[x2 + 1][y2 + 1] += c;
    }

    // 前缀和还原并输出
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1];
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}