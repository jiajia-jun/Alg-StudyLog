#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>

using namespace std;

unordered_map<int, vector<int>> log; // 用来存储 id和它的点赞的时间情况
set<int> ids;// 存储 id
vector<int> re; // 存储热帖结果

int main(){
    // 长度为d的时间段，不少于k个点赞
    int n, d, k;
    cin>> n>> d>> k;

    // 存储日志信息，每一个 id对应它自己的时间
    while(n--){
        int ts, id;
        cin>> ts>> id;
        log[id].push_back(ts);
        ids.insert(id);
    }

    // 对每一个 id逐个计算
    for(int id:ids){
        auto &tm= log[id];
        // 先对时间轴排序，方便双指针
        sort(tm.begin(), tm.end());

        // 滑动窗口
        // 这里由于要求的是 [T, T+d)时间段内的点赞
        // 所以左右指针的时间差必须小于 d
        for(int i=0, j=0; i<tm.size(); ++i){
            // 当时间差大于 d [T, T+d)，左指针右移
            while(tm[i]- tm[j]>= d) j++;

            // 由于每一个日志只会增加一个点赞，所以这里直接看窗口长度
            if(i-j+1>= k){
                // 记录结果
                re.push_back(id);
            }
        }
    }

    //对结果排序+去重
    sort(re.begin(), re.end());
    re.erase(unique(re.begin(), re.end()), re.end());

    for(int x: re){
        cout<<x << '\n';
    }
    
}