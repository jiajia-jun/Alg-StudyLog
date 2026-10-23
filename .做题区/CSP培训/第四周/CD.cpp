#include<iostream>
#include<string>
using namespace std;

string s;
int vis[30], n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n>> s;
    for(int i=0; i<n; ++i){
        // 大写
        if(s[i]>=65 && s[i]<=90){
            vis[s[i]-65]++;
        }
        // 小写
        else vis[s[i]-97]++;
    }
    for(int i=0; i<26; ++i){
        if(!vis[i]){
            cout<< "NO";
            return 0;
        }
    }
    cout<< "YES";
}