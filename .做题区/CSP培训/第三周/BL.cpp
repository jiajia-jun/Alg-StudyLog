#include<iostream>
#include<deque>
using namespace std;

const int N= 200010;
deque<int> q;
int a[N], s[N], n, r;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    for(int i=1; i<=n; ++i) cin>> a[i];
    for(int i=1; i<=n; ++i){
        s[i]= s[i-1]+ a[i];
       // cout<< s[i]<<' ';
    }

    s[0]= 0, r= s[1];
    q.push_back(0);
    for(int i=1; i<=n; ++i){
        r=max(r, s[i]-s[q.front()]);
        
        while(q.size() && s[i]<s[q.back()]) q.pop_back();
        
        q.push_back(i);
    }
    cout<< r;
}