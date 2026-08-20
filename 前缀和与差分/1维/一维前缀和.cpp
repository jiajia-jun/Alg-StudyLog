#include<iostream>

using namespace std;

const int N=1000;

int a[N],s[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //输入n个数，查询m次索引区间[l,r]的和(l>=0,r>=0)
    int n, m;
    cin>>n >> m;
    for(int i=1; i<=n; ++i) cin>>a[i];

    //前缀和
    for(int i=1; i<=n; ++i){
        s[i]= s[i-1]+ a[i];
        //也可以直接采用一个数组就实现前缀和 a[i]= a[i-1]+ a[i]; 前提是原数组不再被使用了
    }

    while(m--){
        int l, r; //l，r均为一段1-base区间
        cin>>l >>r;
        cout<< s[r]-s[l-1] << '\n';
    }
}