#include<iostream>
#include<set>
using namespace std;

int n;
set<int> s;

int main(){
    cin>> n;
    while(n--){
        int t;
        cin>> t;
        if(!s.count(t)) s.insert(t);
        else s.erase(t);
    }
    cout<< s.size();
}