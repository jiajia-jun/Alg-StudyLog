#include<iostream>
#include<string>
#include<map>
using namespace std;

string s;
map<char, int> m;

int main(){
    cin>> s;
    for(char c: s) m[c]++; 
    if(m['a']&& m['b']&& m['c']) cout<< "Yes";
    else cout<< "No";
}