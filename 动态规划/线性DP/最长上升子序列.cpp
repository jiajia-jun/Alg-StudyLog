#include<iostream>
using namespace std;

const int N=10010;
int a[N], b[N], n, len;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    for(int i=1; i<=n; ++i) cin>> a[i];

    len=1, b[1]= a[1];
    for(int i=2; i<=n; ++i){
        if(b[len]<a[i]) b[++len]= a[i];
        else{
            // 寻找最后一个小于a[i]的元素下标
            int l= 0, r= len+1;
            while(l+1<r){
                int mid= l+r >> 1;
                if(b[mid]<a[i]) l=mid;
                else r= mid;
            }
            b[l+1]= a[i];// 替换第一个大于等于a[i]的元素
        }
    }
    cout<< len;
}