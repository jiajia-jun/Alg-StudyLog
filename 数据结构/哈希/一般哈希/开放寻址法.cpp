#include<iostream>
#include<cstring>
#include<string>

using namespace std;

// 开放寻址法一般取 2到 3倍的大小的数组
// 取模操作用质数也可以有效避免冲突
const int N= 200003;
const int nul= 0x3f3f3f3f;

// hsh[k]: 哈希下标为 k的位置对应的数值
int hsh[N];

// 插入一个数
void ins(int x){
    int k= (x% N+ N)% N;
    int cnt=0; // 计数器
    // 如果当前哈希下标处没有空位，就往后找直到有空位
    while(hsh[k] != nul && hsh[k] !=x){
        k++, cnt++;
        if(k== N) k=0; // 到头还没有找到就从第一个开始重新来
        if(cnt>= N) return;
    }
    hsh[k]= x; //插入新的数字
}

// 返回数 x的下标 
int find(int x){
    int k= (x% N+ N)% N;
    int cnt=0; // 计数器
    while(hsh[k] != nul && hsh[k] !=x){
        k++, cnt++;
        if(k== N) k=0; // 到头还没有找到就从头开始重新来
        if(cnt>= N) return -1;
    }
    return k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 初始化 hsh

    memset(hsh, 0x3f, sizeof(hsh));

    int n;
    cin>> n;
    while(n--){
        string op;
        int x;
        cin>> op;
        if(op == "I"){
            cin>> x;
            ins(x);
        }
        else if(op == "Q"){
            cin>> x;
            int pos= find(x);
            if(pos!= -1 && hsh[pos]== x){
                cout<<"Yes\n";
            }
            else cout<<"No\n";
        }
    }
    return 0;
}