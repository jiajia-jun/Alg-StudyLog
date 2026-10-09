#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s, t;
int main(){
    cin>> s>> t;
    sort(s.begin(), s.end(), [](char a, char b){
        return a<b;
    });
    sort(t.begin(), t.end(), [](char a, char b){
        return a>b;
    });
    if(s<t) cout<<"Yes";
    else cout<<"No";
}