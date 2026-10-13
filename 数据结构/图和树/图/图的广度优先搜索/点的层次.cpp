#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N= 100010;
int h[N], e[N], nxt[N], idx;
int d[N], n, m;
queue<int> q;

void init(){
    memset(h, -1, sizeof(h));
    memset(d, -1, sizeof(d));
}

void add(int a, int b){
    e[idx]= b;
    nxt[idx]= h[a];
    h[a]= idx++;
}

int bfs(){
    d[1]= 0;
    q.push(1);

    while(!q.empty()){
        int t= q.front();
        q.pop();

        for(int i= h[t]; i!=-1; i= nxt[i]){
            int j= e[i];
            if(d[j]== -1) {
                d[j]= d[t]+1;
                q.push(j);
            }
        }
    }
    return d[n];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    cin>> n>> m;
    for(int i=1; i<=m; ++i){
        int a, b;
        cin>> a>> b;
        add(a, b);
    }
    cout<< bfs();
}
