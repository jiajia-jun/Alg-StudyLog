#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string, int> m;
int mx, n;

int main(){
    cin>> n;
    while(n--){
        string s;
        cin>> s;
        m[s]++;
        mx= max(mx, m[s]);
    }

    for(auto &x: m){
        if(x.second== mx) cout<< x.first<< '\n';
    }
}