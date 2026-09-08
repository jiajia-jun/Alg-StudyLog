#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>> t;
    while(t--){
        int n;
        cin>> n;
        vector<int> a;
        vector<int> b;
        for(int i=0; i<n; ++i){
            int x;
            cin>> x;
            a.push_back(x);
        }
        b= a;
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()),b.end());
        
        for (int i = 0; i < n; ++i) {
            int r = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
            cout << r << (i == n - 1 ? '\n' : ' ');
        }
    }
}