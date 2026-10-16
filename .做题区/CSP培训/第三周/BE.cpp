#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> a;
vector<int> b;
int n;

int main(){
    cin>> n;
    for(int i=0; i<n; ++i){
        int t;
        cin>> t;
        a.push_back(t);
        b.push_back(t);
    }

    sort(a.begin(), a.end());
    int cnt= 0;
    for(int i=0; i<n; ++i){
        if(a[i]!=b[i]) cnt++;
    }
    if(cnt>2) cout<<"NO";
    else cout<<"YES";
}