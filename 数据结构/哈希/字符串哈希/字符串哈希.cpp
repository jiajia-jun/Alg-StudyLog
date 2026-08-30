#include<iostream>
#include<string>
using namespace std;

typedef unsigned long long uii;

const int N= 100010;
// P常用 131和 13331这两个经验值
const int P= 131;

// hsh[i]: 记录[1, i]区间的字符串的哈希值
// p[k]: 存储p的 k次幂
uii hsh[N], p[N];

// 求[l, r]字符串的哈希值(l, r>=1): hsh[r]- hsh[l-1]* (p^区间长度)
// 这里要返回 uii
uii get_hash(int l, int r){
    return hsh[r]- hsh[l-1]* p[r-l+1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string s;
    cin>> n>> m;
    cin>> s;

    // 初始化
    // 计算每一段前缀的哈希值和 P的不同次幂
    p[0]= 1; // P^0= 1
    for(int i=1; i<=n; ++i){
        hsh[i]= hsh[i-1]* P+ s[i-1];
        p[i]= p[i-1]* P;
    }

    while(m--){
        int l1, r1, l2, r2;
        cin>> l1>> r1>> l2>> r2;
        // 比较两个区间的哈希值是否相同，哈希值相同就代表字符串相同
        if(get_hash(l1, r1)== get_hash(l2, r2)){
            cout<<"Yes\n";
        }
        else cout<<"No\n";
    }
}