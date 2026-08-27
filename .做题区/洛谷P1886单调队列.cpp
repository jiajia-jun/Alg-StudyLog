#include<iostream>
#include<deque>
using namespace std;

const int N= 1000010;
int a[N];
deque<int> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin>> n>> k;
    for(int i=1; i<=n; ++i){
        cin>> a[i];
    }
    for(int i=1; i<=n; ++i){
        while(!q.empty() && a[q.back()]>= a[i]) q.pop_back();

        while(!q.empty() && q.front()<= i-k) q.pop_front();

        q.push_back(i);

        if(i-k>=0) cout<<a[q.front()]<<' ';
    }

    q.clear();
    cout<< '\n';
    for(int i=1; i<=n; ++i){
        while(!q.empty() && a[q.back()]<= a[i]) q.pop_back();

        while(!q.empty() && q.front()<= i-k) q.pop_front();

        q.push_back(i);

        if(i-k>=0) cout<<a[q.front()]<<' ';
    }
}