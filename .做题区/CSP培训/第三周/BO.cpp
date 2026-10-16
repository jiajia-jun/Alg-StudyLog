#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

vector<int> v;
int n, h, r;

int main(){
    cin>> n>> h;
    for(int i=0; i<n; ++i){
        int t;
        cin>> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());
    auto t=upper_bound(v.begin(), v.end(), h);
    
    r= (v.end()-t)*2+ t-v.begin();
    cout<< r;
}