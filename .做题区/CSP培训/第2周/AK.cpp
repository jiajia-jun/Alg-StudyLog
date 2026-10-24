#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;
int r;

int upt(int &x){
    if(x%10== 0) return x;
    return (x/10+1) *10;
}

int main(){
    for(int i=0; i<5; ++i){
        int t;
        cin>> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), [](int &a, int &b){
        return abs(upt(a)-a)< abs(upt(b)-b);
    });

    for(int i=0; i<5; ++i){
        if(i== 4) r+= v[i];
        else r+= upt(v[i]);
    }
    cout<< r;
}