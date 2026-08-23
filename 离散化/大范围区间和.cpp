#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 300010;

typedef pair<int, int> pii;

// 1.存储所有出现过的原始坐标（包括修改位置 x 和询问端点 l, r），用于离散化
// 2.存放离散化后的相对位置情况
vector<int> list;

// a 用来存放离散化后的相对索引下对应的值（1-base）
// s 用来存放前缀和（1-base）
int a[N], s[N];

// origin 存放修改操作：{修改位置x, 值c}
// query  存放询问操作：{l, r}（均为原始坐标）
vector<pii> origin, query;


int main(){
    int n, m;
    cin>> n>> m;
    for(int i=0; i<n; ++i){
        int x, c;
        cin>> x>> c;

        origin.push_back({x, c});

        list.push_back(x);
    }

    for(int i=0; i<m; ++i){
        int l, r;
        cin>> l>> r;
        query.push_back({l, r});

        // list存入询问区间的左右端点，为离散化压缩做准备
        list.push_back(l);
        list.push_back(r);
    }

    sort(list.begin(), list.end()); // 排序得到相对位置
    list.erase(unique(list.begin(), list.end()), list.end()); // 去重


    for(int i=0; i<n; ++i){
        //下面两行是为了把有值的位置录入a中
        auto t= lower_bound(list.begin(), list.end(), origin[i].first); 
        a[t-list.begin()+1] += origin[i].second;// 从1开始可以省去前缀和的边界问题
    }

    // 对a[]进行前缀和
    for(int i=1; i<= list.size() ; ++i){
        s[i] = s[i-1] + a[i];
    }

    // 计算离散化后的等效索引
    for(auto &q:query){
        int origin_l = q.first;
        int origin_r = q.second;
        
        // 由于前缀和数组从下标1开始，所以这里要加上1
        int l= lower_bound(list.begin(), list.end(), origin_l) - list.begin()+1;
        int r= lower_bound(list.begin(), list.end(), origin_r) - list.begin()+1;
        cout<< s[r]- s[l-1]<< '\n';
    }
    return 0;
}