#include<iostream>
#include<string>
using namespace std;

const int N= 100010;
// p[x]代表着：编号为 x的节点的父节点编号
int p[N]; 

// 查找编号为 x的节点的祖宗节点
int find(int x){
    // 根节点特点：p[x]= x
    if(p[x]!= x) p[x]= find(p[x]);
    return p[x];
}

int main(){
    int n, m;
    cin>> n>> m;
    // 初始化，每个数字一个集合
    for(int i=1; i<=n; ++i){
        p[i]= i;
    }
    while(m--){
        string op;
        int a, b;
        cin>> op>> a>> b;
        // 集合合并
        if(op == "M"){
            p[find(a)]= find(b); 
        }
        // 查找两元素是否为相同集合
        else if(op == "Q"){
            if(find(a) == find(b)){
                cout<< "Yes\n";
            }
            else cout<<"No\n";
        }
    }
    return 0;
}