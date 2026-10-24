#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, r;
vector<int> p;

int main(){
    cin>> n;
    for(int i=0; i<n; ++i){
        int t;
        cin>> t;
        p.push_back(t);
    }
    sort(p.begin(), p.end());
    p[p.size()-1]/= 2;
    for(int &x:p){
        r+= x;
    }
    cout<< r;
}