#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    // 先按照左端点排序（sort默认按照pair.first升序排列的）
    sort(a.begin(), a.end());

    vector<pii> res;
    for (auto i : a) {
        // 当前区间的起点，大于上一个区间的终点，说明是独立区间
        if (res.empty() || i.first > res.back().second) {
            res.push_back(i);
        } else {
            // 如果当前区间起点，小于上一个区间终点，区间存在重合
            // 上一个区间终点取此区间终点和其区间终点最大值
            // 因为已经按照左端点从小到大排序了，就没有必要再写res.back().first = min(res.back().first, i.first)了
            res.back().second = max(res.back().second, i.second);
        }
    }

    cout << res.size() << endl;
    return 0;
}