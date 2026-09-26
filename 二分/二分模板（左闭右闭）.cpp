#include<iostream>

using namespace std;

const int N= 100010;

int a[N];

// 找第一个 > t     l<= mid< r
int find1(int l, int r, int t){
    while(l< r){
        int mid= (l+r)>> 1;// 向下取整
        if(a[mid]>=t) r= mid;
        else l= mid+1;
    }
    return l;
}

// 找最后一个 < t     l< mid<= r
int find2(int l, int r, int t){
    while(l< r){
        int mid= (l+r+1)>> 1;// 向上取整
        if(a[mid]< t) l= mid;
        else r= mid-1;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin>> n>> q;
    for(int i=1; i<=n; ++i){
        cin>> a[i];
    }
    while(q--){
        int t;
        cin>> t;
        cout<< find1(1, n, t)<<'\n';
        cout<< find2(1, n, t)<<'\n';
        cout<< '\n';
    }
}