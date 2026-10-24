#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> ss;
int n, l;

int main(){
    cin>> n>> l;
    for(int i=0; i<n; ++i){
        string s;
        cin>> s;
        ss.push_back(s);
    }

    sort(ss.begin(), ss.end());
    for(string &s: ss){
        cout<< s;
    }
    return 0;
}