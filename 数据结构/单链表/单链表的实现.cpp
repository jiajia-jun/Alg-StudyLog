#include<iostream>
using namespace std;

//----------------单链表的数组实现---------------
const int N = 100010;

// v[k]存放编号为k的节点数值
// nxt[k]存编号为k的节点的下一个节点编号
int v[N], nxt[N];

// head为头节点编号
// id用于分配节点编号
int head, id;

// 初始化（-1代表指向空）
void init(){
    head= -1, id= 0;
}

// 添加到链表头部（头插法）
void add_to_head(int val){
    v[id]= val; //设置新节点值
    nxt[id]= head; //设置新节点指向
    head= id++; //更新head指针，并给id（可分配编号）+1
}

// 添加到编号为k的节点后
void add_to(int k, int val){
    v[id]= val; //设置新节点值
    nxt[id]= nxt[k]; //设置新节点指向（为编号为k的节点的指向）
    nxt[k]= id++; //把编号为k的节点指向新节点，并给id+1
}

// 删除编号为k的节点的后一个节点
void rmv_after(int k){
    if (nxt[k] == -1) return; // 如果 k节点是最后一个节点就直接返回
    int p_after_k = nxt[k]; // 编号 k节点后一个节点的编号
    nxt[k]= nxt[p_after_k]; // 把 k的指向改为后一个节点的指向
}

int main(){
    init();
    int m;
    cin>> m;
    while(m--){
        char op;
        int x, k;
        cin>> op;
        if(op == 'H'){
            cin>> x;
            add_to_head(x);
        } 
        else if(op == 'D'){
            cin>> k;
            if(k==0){
                // k=0删除头节点，head指向头节点的下一个节点
                if(head!=-1) head= nxt[head];
            }
            else rmv_after(k-1);
        } 
        else if(op == 'I'){
            cin>> k>> x;
            add_to(k-1, x);
        }
    }

    for(int i= head; i!=-1; i=nxt[i]){
        cout<< v[i] <<' ';
    }
}
