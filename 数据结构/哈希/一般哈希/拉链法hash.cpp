#include<iostream>
#include<cstring>
#include<string>
using namespace std;

// 手写哈希的 N取质数可以有效避免哈希冲突的情况
const int N= 100003;

// h[k]: 哈希下标为 k的数对应的链表head所指向的节点编号（相当于头指针）
// v[i]: 编号为 i的节点对应的数的大小（值）
// nxt[i]: 编号为 i的节点的下一个节点（-1表示无）
// id: 用于分配节点编号
int h[N], v[N], nxt[N], id;

// 插入数 x
void insert(int x){
    int k= (x%N + N)% N;

    v[id]= x;
    nxt[id]= h[k];
    h[k]= id++;
}

// 查找数 x
bool find(int x){
    int k= (x%N + N)% N;

    for(int i= h[k]; i!=-1; i= nxt[i]){
        if(v[i]== x){
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 初始化 h
    memset(h, -1, sizeof(h));

    int n;
    cin>> n;
    while(n--){
        string op;
        int x;
        cin>> op;
        if(op == "I"){
            cin>> x;
            insert(x);
        }
        else if(op == "Q"){
            cin>> x;
            if(find(x)){
                cout<<"Yes\n";
            }
            else cout<<"No\n";
        }
    }
    return 0;
}