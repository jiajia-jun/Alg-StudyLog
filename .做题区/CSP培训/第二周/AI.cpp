#include<iostream>
#include<map>
using namespace std;

int n, m, k, r;
map<int, int> A;

int main(){
    cin>> n>> m;
    for(int i=0; i<n; ++i){
        cin>> k;
        for(int j=0; j<k; ++j){
            int a;
            cin>> a;
            A[a]++;
        }
    }
    for(auto &x:A){
        if(x.second== n) r++;
    }
    cout<< r;
}