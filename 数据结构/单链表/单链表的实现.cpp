#include<iostream>
using namespace std;

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
    v[id]= val; 
    nxt[id]= head; 
    head= id++; 
}

// 添加到编号为k的节点后
void add_to(int k, int val){
    v[id]= val; 
    nxt[id]= nxt[k]; 
    nxt[k]= id++; 
}

// 删除编号为k的节点的后一个节点
void rmv_after(int k){
    if (nxt[k] == -1) return; 
    int p_after_k = nxt[k]; 
    nxt[k]= nxt[p_after_k]; 
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
