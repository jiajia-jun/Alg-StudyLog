#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a, b;
vector<int> c;

int main(){
    cin>> n;
    for(int i=0; i<n; ++i){
        int t;
        cin>> t;
        c.push_back(t);
    }
    sort(c.begin(), c.end(), [](int a, int b){return a>b;});
    for(int i=0; i<n; ++i){
        if(!(i%2)) a+= c[i];
        else b+= c[i];
    }
    cout<< a-b;
}