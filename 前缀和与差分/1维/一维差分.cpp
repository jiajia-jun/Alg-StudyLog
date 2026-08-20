#include<iostream>

using namespace std;

const int N= 100010;
int a[N],d[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>> n>> m;
    for(int i=1; i<=n; ++i) cin>> a[i];

    // 差分数组
    for(int i=1; i<=n; ++i){
        d[i]= a[i]-a[i-1]; 
    }

    while(m--){
        int l, r, c;
        cin>>l >>r >>c;
        d[l]+= c;
        d[r+1]-=c;
    }
    for(int i=1; i<=n; ++i){
        d[i]+=d[i-1]; // 进行一次前缀和
        cout<< d[i]<<' ';
    }
    return 0;
}