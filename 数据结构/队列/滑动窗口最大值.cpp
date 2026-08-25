#include<iostream>
#include<deque>

using namespace std;

const int N= 1000010;
deque<int> q;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin>> n>> k;
    for(int i=1; i<= n; ++i) cin>> a[i]; //1-base存储

    // 输出窗口最小值
    for(int i=1; i<= n; ++i){
        // 队列不为空，且出现了比队列尾部还要小的数字时候
        while(!q.empty() && a[q.back()]> a[i]){
            q.pop_back();
        }

        // 队列不为空，且队列最小的数字滑出窗口范围(左端点下标是i-k+1)
        if(!q.empty() && q.front() < i-k+1){
            q.pop_front();
        }

        q.push_back(i);

        // 出现窗口了
        if(i-k+1>0){
            cout<< a[q.front()]<<' ';
        }
    }

    q.clear();
    cout<<'\n';

    // 输出窗口最大值
    for(int i=1; i<= n; ++i){
        // 队列不为空，且出现了比队列尾部还要小的数字时候
        while(!q.empty() && a[q.back()]< a[i]){
            q.pop_back();
        }

        // 队列不为空，且队列最小的数字滑出窗口范围
        if(!q.empty() && q.front() < i-k+1){
            q.pop_front();
        }

        q.push_back(i);

        // 出现窗口了
        if(i-k+1>0){
            cout<< a[q.front()]<<' ';
        }
    }    
}