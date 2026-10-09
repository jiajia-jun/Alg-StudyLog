#include<iostream>

using namespace std;

const int N=1000;

int a[N],s[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //输入n个数，查询m次索引区间[l,r]的异或和(l>=0,r>=0)
    int n, m;
    cin>>n >> m;
    for(int i=1; i<=n; ++i) cin>>a[i];

    //异或前缀和
    for(int i=1; i<=n; ++i){
        // 异或前缀: s[i] 为前 i 个数的异或和
        // 注意 a[] 为 1-base
        s[i]= s[i-1]^ a[i];
    }

    // 区间[l, r] 的异或和= s[r]^ s[l-1]
    while(m--){
        int l, r; //l，r均为一段 1-base 区间
        cin>>l >>r;
        cout<< (s[r]^ s[l-1]) << '\n'; 
    }
} 