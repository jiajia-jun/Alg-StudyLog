#include<iostream>

using namespace std;

const int N= 1000010;
// hp为堆，sz为堆大小
int hp[N], sz;

// 下滤操作（i为编号）
void down(int i){
    int t= i;

    // 对比孩子节点的大小
    if(i*2<= sz && hp[i*2]< hp[t]) t = i*2;
    if(i*2+1<= sz && hp[i*2+1]< hp[t]) t= i*2+1;

    if(i!=t){
        swap(hp[i], hp[t]);
        down(t);
    }
}
// 上滤操作
void up(int i){
    while(i/2!= 0 && hp[i/2]> hp[i]){
        swap(hp[i/2], hp[i]);
        i/= 2;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>> n;
    while(n--){
        int op;
        cin>> op;
        // 插入一个数
        if(op == 1){
            int x;
            cin>> x;
            hp[++sz]= x;
            up(sz);
        }
        // 输出堆中最小的数（小分堆自然是堆顶）
        else if(op == 2){
            cout<< hp[1]<< '\n';
        }
        // 删除最小的数
        else if(op == 3){
            // 堆顶改为堆尾，堆大小减 1
            hp[1]= hp[sz--];
            down(1);
        }
    }
    return 0;
}