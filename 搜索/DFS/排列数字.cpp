#include<iostream>

using namespace std;

const int N= 10;

int n;
// num[i]: i数字是否被使用过
// re[]: 用来记录结果
int num[N], re[N];

// p代表所填充的下标位置
void dfs(int p){
    // 由于 p表示下标，所以当 p= n的时候就代表数字全填完，直接输出
    if(p == n){
        for(int i=0; i< n; ++i){
            cout<< re[i] << ' ';
        }
        cout<< '\n';
    }
    // 逐个枚举数字填入
    for(int i=1; i<= n; ++i){
        // 数字没有被使用，就直接填入
        if(!num[i]){
            re[p]= i;
            num[i]= 1;
            // 进入下一个数位
            dfs(p+1);
            // 走到头了上面这个 dfs()就会退出，就需要恢复初始状态
            // 恢复初始状态
            num[i]= 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    // 从第 0号位开始填入
    dfs(0);
    return 0;
}