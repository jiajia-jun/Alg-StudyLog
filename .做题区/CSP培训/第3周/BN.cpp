#include<iostream>
#include<queue>
using namespace std;

int n, r;
queue<int> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    for(int i=1; i<=n; ++i){
        int t;
        cin>> t;
        if(q.empty()) q.push(t);
        else{
            if(t>=q.back()) {
                q.push(t);
                r=max(r, (int)q.size());
            }
            else{
                q= queue<int>();
                q.push(t);
            }
        }
    }
    r=max(r, (int)q.size());
    cout<< r;
}