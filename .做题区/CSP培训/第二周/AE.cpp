#include<iostream>
#include<map>
#include<string>
using namespace std;

int N, M, r;
map<string, int> a;
int main(){
    cin>> N;
    string t;
    for(int i=0;i<N;++i){
        cin>> t;
        a[t]++;
    }
    cin>> M;
    for(int i=0; i<M; ++i){
        cin>> t;
        a[t]--;
    }
    for(auto &x:a){
        r=max(r, x.second);
    }
    cout<< r;
}