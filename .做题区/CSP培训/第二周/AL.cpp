#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
typedef pair<int, pair<string, int>> pisi;

vector<pisi> v;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    for(int i=1; i<=n; ++i){
        string s;
        int p;
        cin>> s>> p;
        v.push_back({i, {s, p}});
    }
    sort(v.begin(), v.end(), [](pisi &a, pisi &b){
        if (a.second.first != b.second.first) {
            return a.second.first < b.second.first;
        }
        return a.second.second> b.second.second;
    });

    for(pisi &x: v){
        cout<< x.first<< '\n';
    }
}