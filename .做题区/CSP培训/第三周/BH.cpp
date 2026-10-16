#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;
int n, k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n>> k;
    while(n--){
        int t;
        cin>> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    cout<< v.end()-lower_bound(v.begin(),v.end(),k);
}