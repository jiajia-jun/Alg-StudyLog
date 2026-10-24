#include<iostream>
#include<vector>
using namespace std;

int r=INT16_MAX;
int s[110], n;
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    v.push_back(0);
    for(int i=1; i<=n; ++i){
        int t;
        cin>> t;
        v.push_back(t);
    }
    for(int i=1; i<=n; ++i){
        s[i]=s[i-1]+ v[i];
    }
    for(int i=0; i<n; ++i){
        r=min(r, abs(s[n]-2*s[i]));
    }
    cout<< r;
}