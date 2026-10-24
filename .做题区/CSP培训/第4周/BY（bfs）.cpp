#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
const int N = 110;
char a[N][N];
bool vis[N][N];
int n, m;
queue<pii> q;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs(int sx, int sy) {
    q.push({sx, sy});
    vis[sx][sy] = true;

    while (!q.empty()) {
        pii t = q.front();
        q.pop();
        int x=t.first, y=t.second;
        for (int k = 0; k < 8; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (vis[nx][ny]) continue;
            if (a[nx][ny] != 'W') continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'W' && !vis[i][j]) {
                ++ans;
                bfs(i, j);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}