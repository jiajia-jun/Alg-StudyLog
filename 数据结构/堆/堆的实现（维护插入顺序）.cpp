#include<iostream>
#include<string>
using namespace std;

const int N= 100010;

// x: 堆位置
// h[x]: 堆的 x位置的存储的值
// hp[x]: heap to point，堆的 x位置对应的插入顺序
// ph[k]: point to heap，第 k个插入的数在堆中的位置
int h[N], hp[N], ph[N];

// sz记录堆的大小，m记录插入顺序
int sz, m;

// 堆交换，既要交换值，也要维护插入顺序的关系
void hswap(int x, int y){
    // 先换 ph，再换 hp（因为 ph依赖于目前的 hp情况）
    swap(ph[hp[x]], ph[hp[y]]);
    swap(hp[x], hp[y]);
    swap(h[x], h[y]);
}

// 对 x堆位置实现下滤操作
void down(int x){
    int t= x;
    if(x*2<= sz && h[x*2]< h[t]) t= x*2;
    if(x*2+1<= sz && h[x*2+1]< h[t]) t= x*2+1;

    if(t != x){
        hswap(x, t);
        down(t);
    }
}

// 对 x堆位置实现上滤
void up(int x){
    // 判断有没有父节点
    while(x/2!= 0 && h[x/2]> h[x]){
        hswap(x, x/2);
        x /= 2;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>> n;
    while(n--){
        string op;
        cin>> op;
        // 插入
        if(op== "I"){
            int t;
            cin>> t;
            sz++, m++;            
            h[sz]= t;
            hp[sz]= m, ph[m]= sz;
            
            up(sz);
        }
        // 输出最小值
        else if(op == "PM"){
            cout<< h[1]<< '\n';
        }
        // 删除最小值
        else if(op == "DM"){
            // 先交换，再减小 sz，最后滤
            hswap(1, sz);
            sz--;
            down(1); 
        }
        // 删除第 k个插入的数
        else if(op == "D"){
            int k;
            cin>> k;
            int p= ph[k];// ph[k]获得这个数在堆中的位置
            hswap(p, sz);
            sz--;
            down(p);
            up(p);
        }
        // 修改第 k个插入的数，将其变为 x
        else if(op == "C"){
            int k, x;
            cin>> k>> x;
            int p= ph[k];
            h[p]= x;
            down(p);
            up(p);
        }
    }
}