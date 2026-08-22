#include<iostream>
#include<map>

using namespace std;

const int N=100010;

map<int, int> mp;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>> n;
    for(int i=0; i<n; ++i) cin>> a[i];

    // 这里有点晦涩难懂
    int re=0;
    for(int i=0, j=0; i<n; ++i){
        mp[a[i]]++;
        while(j<i && mp[a[i]]>1){
            mp[a[j]]--;
            j++;
        }
        re= max(re,i-j+1);
    }
    cout<< re <<' ';
}