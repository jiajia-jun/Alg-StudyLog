#include<iostream>

using namespace std;

const int N= 100010;

// 这里实现的是小分堆
// hp[x]（1-base） 存储的是编号为 x的节点的值，x*2处为左节点，x*2+1处为右节点
int hp[N], sz;

// 下滤操作
void down(int id){
    int t= id;
    // 这里要和 hp[t]进行比较，不可用 hp[id]
    if(id*2<= sz && hp[id*2]< hp[t]) t= id*2;
    if(id*2+1<= sz && hp[id*2+1]< hp[t]) t= id*2+1;

    if(id != t){
        swap(hp[id], hp[t]);
        down(t);
    }
}

// 上滤操作
void up(int id){
    while(id<= sz && hp[id/2]> hp[id]){
        swap(hp[id], hp[id/2]);
        id = id/2;
    }
}

int main(){
    int n, m;
    cin>> n>> m;

    // 构建堆
    for(int i=1; i<=n; ++i){
        cin>> hp[i];
        sz++;
    }
    for(int i= n/2; i!=0; --i){
        down(i);
    }

    while(m--){
        // 输出根节点（小分堆根节点值最小）
        cout<< hp[1]<<' '; 
        hp[1]= hp[sz--];
        down(1);
    }
}