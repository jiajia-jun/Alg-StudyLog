#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> a;

int main(){
    cin>> n;
    for(int i=0; i<n; ++i){
        int x;
        cin>> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    cout<< a.size();
}