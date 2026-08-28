#include<iostream>
#include<string>
using namespace std;

const int N= 100010;

// p[x]：存储编号为 x的节点的父节点
// s[x]：编号为 x的连接点的数量，x为祖宗根节点
int p[N], s[N];

// 查找编号为 x的节点的祖宗节点
int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>> n>> m;
    for(int i=1; i<=n; ++i){
        p[i]= i;
        s[i]= 1;
    }

    while(m--){
        string op;
        int a, b;
        cin>> op;
        // a, b连一条边
        if(op == "C"){
            cin>> a>> b;
            // 如果 a，b已经相连了就直接跳过（注意这里）
            if(a==b || find(a)==find(b)) continue;
            // 把 b作为新的根节点进行合并
            s[find(b)]+= s[find(a)];
            p[find(a)]= find(b);
            
        }
        else if(op == "Q1"){
            cin>> a>> b;
            if(find(a)== find(b)) cout<< "Yes\n";
            else cout<<"No\n";
        }
        else if(op == "Q2"){
            cin>> a;
            cout<< s[find(a)]<<'\n';
        }
    }
    return 0;
}