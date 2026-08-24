#include<iostream>
#include<string>
using namespace std;

const int N= 100010;

// v[k]:编号为 k的节点的值
// l[k]:编号为 k的节点的左侧节点编号
// r[k]:编号为 k的节点的右侧节点编号
// idx: 可分配的节点编号
int v[N], l[N], r[N], idx;

// 初始化，规定左侧初始哨兵节点编号为 0，右侧为 1
void init(){
    l[1]= 0, r[0]= 1;
    idx= 2;
}

// 向节点 k右侧添加新的节点
void add_r(int k, int val){
    // 新节点信息
    v[idx]= val;
    r[idx]= r[k], l[idx]= k;

    // 原 k节点右侧的 r[k]节点左指向新节点
    l[r[k]]= idx;
    // 原 k节点指向新节点
    r[k]= idx++;

}

// 删除 k节点
void rmv(int k){
    // k节点左侧的 l[k]节点右指向 k节点的右侧 r[k]
    r[l[k]]= r[k];

    // k节点右侧的 r[k]节点左指向 k节点的左侧 l[k]
    l[r[k]]= l[k];
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int m;
    cin>> m;
    while(m--){
        string op;
        // k是第 k个插入的节点
        int x, k;
        cin>> op;

        //最左侧插入
        if(op == "L"){
            cin>> x;
            add_r(0, x);
        }

        // 最右侧插入
        else if(op == "R"){
            cin>> x;
            add_r(l[1], x);
        }

        else if(op == "D"){
            cin>> k;
            rmv(k+1);
        }

        // 添加到节点的左侧
        else if(op == "IL"){
            cin>> k>> x;
            add_r(l[k+1], x);
        }

        // 添加到节点的右侧
        else if(op == "IR"){
            cin>> k>>x;
            add_r(k+1,x);
        }
    }

    for(int i= r[0];i!= 1; i=r[i]){
        cout<< v[i]<< ' ';
    }
}