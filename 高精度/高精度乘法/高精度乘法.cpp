#include<iostream>
#include<vector>
using namespace std;

vector<int> a, c;

void mul(vector<int>& a, int b){
    int t=0;
    for(int i=0; i<a.size() || t!=0; ++i){
        if(i<a.size()) t += a[i]*b;
        c.push_back(t%10);
        t /= 10;
    }
    // 去除前导0
    while(c.size()>1 && c.back()==0 ) c.pop_back();
}

int main(){
    string x;
    cin>> x;
    for(int i= x.size()-1; i>=0; --i){ a.push_back(x[i]-'0'); }

    int b;
    cin>>b;

    mul(a,b);

    for(int i= c.size()-1; i>=0; --i){
        cout<<c[i];
    }
}