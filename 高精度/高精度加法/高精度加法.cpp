#include<iostream>
#include<vector>

using namespace std;

vector<int> a,b,c;

void add(vector<int>& a, vector<int>& b){
    int t=0;
    for(int i=0; i<a.size()||i<b.size(); ++i){
        if(i<a.size()) t+= a[i];
        if(i<b.size()) t+= b[i];
        c.push_back(t%10);
        t= t/10;
    }
    if(t==1){
        c.push_back(1);
    }
}

int main(){
    string x, y;
    cin>> x>> y;

    for(int i= x.size()-1; i>=0; --i){ a.push_back(x[i]-'0'); }
    for(int i= y.size()-1; i>=0; --i){ b.push_back(y[i]-'0'); }

    add(a,b);

    for(int i= c.size()-1; i>=0; --i){
        cout<<c[i];
    }
}