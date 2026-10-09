#include<iostream>
#include<string>
#include<set>
using namespace std;

string s;
int r, n;

int main(){
    int n;
    cin>> n>>s;
    for(int i=1; i<s.length()-1;++i){
        set<char> ls, rs;
        for(int j=0; j<i; ++j){
            ls.insert(s[j]);
        }
        for(int k=i; k<s.length(); ++k){
            if(ls.count(s[k])) rs.insert(s[k]);
        }
        r= max(r, (int)rs.size());
    }
    cout<< r;

}