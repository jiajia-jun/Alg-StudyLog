#include<iostream>
#include<map>
using namespace std;

int n;
map<int, int> m;

int main(){
    cin>> n;
    for(int i=1; i<=4*n-1; ++i){
        int t;
        cin>> t;
        m[t]++;
    }
    for(int i=1; i<=n; ++i){
        if(m[i]<4){
            cout<< i;
            return 0;
        }
    }
}