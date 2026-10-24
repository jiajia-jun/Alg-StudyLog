#include<iostream>
#include<vector>
using namespace std;

vector<int> a;
vector<int> b;
int n;
int r= INT32_MAX;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    for(int i=0; i<n; ++i){
        int aa, bb;
        cin>> aa>> bb;
        a.push_back(aa);
        b.push_back(bb);
    }
    for(int i=0; i<n; ++i){
        r= min(r, a[i]+b[i]);
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(i==j) continue;
            r= min(r, max(a[i],b[j]));
        }
    }
    cout<< r;
}