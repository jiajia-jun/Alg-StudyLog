#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int N= 1000010;

string s1, s2;
char s[N], p[N];
int nxt[N];
vector<int> re;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> s1>> s2;
    for(int i=0; i< s1.length(); ++i){
        s[i+1]= s1[i];
    }
    for(int i=0; i< s2.length(); ++i){
        p[i+1]= s2[i];
    }

    for(int i=2, j=0; i<=s2.length(); ++i){
        while(j !=0 && p[j+1]!=p[i]){
            j = nxt[j];
        }
        if(p[j+1] == p[i]){
            j++;
        }
        nxt[i]= j;
    }

    for(int i=1, j=0; i<=s1.length(); ++i){
        while(j !=0 && p[j+1]!=s[i]){
            j = nxt[j];
        }
        if(p[j+1] == s[i]){
            j++;
        }
        if(j == s2.length()){
            re.push_back(i-j+1);
        }
    }
    for(int x:re){
        cout<< x << '\n';
    }
    for(int i=1; i<=s2.length(); ++i){
        cout<< nxt[i] << ' ';
    }
}