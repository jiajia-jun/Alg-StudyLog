#include<iostream>
using namespace std;

const int N= 1000010;

int b[N], a[N], dp[N], pre_ou[N], pre_ji[N];

void init(int l, int r){
    for(int i=1; i<= r-l+1; ++i){
        a[i]= b[i+l-1];
        if(i%2==0) pre_ou[i/2]= pre_ou[i/2-1]^a[i];
        else pre_ji[(i+1)/2]= pre_ji[(i+1)/2-1]^ a[i];
    }
}
// 计算区间的奇数位置异或和
// l, r为 a[]中 [L, R]元素位置在1-base上的映射位置
int find(int l, int r){
    //if(l>r) return 0;
    int s= 0;
    if(l%2==0) s= pre_ou[r/2]^ pre_ou[l/2-1];
    else s= pre_ji[(r+1)/2]^ pre_ji[(l+1)/2-1];
    if(s==0) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin>> n>> q;
    for(int i=1; i<=n; ++i){
        cin>> b[i];
    }
    while(q--){
        int L, R;
        cin>> L>> R;
        init(L, R);
        // 转换为映射位置
        int len= R-L+1;
        for(int i=1; i<=len; ++i){
            for(int j=0; j<i;++j){
                dp[i]= max(dp[i], dp[j]+find(j+1, i));
            }
            //cout<<dp[i]<<'\n'<<'\n';
        }
        cout<< dp[len]<< '\n';
        for(int i=0; i<=len; ++i) {
            dp[i]= 0, pre_ji[i]= 0, pre_ou[i]= 0; 
        }     
    }  
}

