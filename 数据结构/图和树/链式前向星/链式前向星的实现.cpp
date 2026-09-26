#include<iostream>
#include<cstring>
using namespace std;

const int N= 100010;
int h[N], e[N], nxt[N], idx;

// 初始化
void init(){
    memset(h, -1, sizeof(h));
}

// 建立 编号为a的节点 -> 编号为b的节点单向边
void add1(int a, int b){
    e[idx]= b;
    nxt[idx]= h[a];
    h[a]= idx++;
}

// 建立 编号为a的节点 <-> 编号为b的节点无向边
void add2(int a, int b){
    e[idx]= b;
    nxt[idx]= h[a];
    h[a]= idx++;

    e[idx]= a;
    nxt[idx]= h[b];
    h[b]= idx++;
}

