#include<iostream>
#include<map>
using namespace std;

map<char, int> m;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    while(n--){
        char t;
        cin>> t;
        m[t]++;
    }
    if(m['A']>m['D']) cout<<"Anton";
    else if(m['A']<m['D']) cout<<"Danik";
    else cout<< "Friendship";
}