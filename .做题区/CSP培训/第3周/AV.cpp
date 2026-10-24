#include<iostream>
#include<queue>
using namespace std;

long long a, n, r;// 最坏情况，n=10e5，r到5*10e9，超过int
queue<long long> q;

int main(){
    cin>> n;
    for(long long i=1; i<=n; ++i) {
        cin>> a;
        if(q.empty()) q.push(a);
        else{
            if(a>q.back()) q.push(a);
            else {
                r+= (q.size()-1)*q.size()/2+ q.size();
                q= queue<long long>();
                q.push(a);
            }
        }
    }
    // 这里是防止出现1 2 3 4这种情况（不加上就为0了）
    r+= (q.size()-1)*q.size()/2+ q.size();
    cout<< r;

}