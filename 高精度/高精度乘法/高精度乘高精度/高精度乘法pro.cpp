#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> a,b;

vector<int> mul(vector<int>& a, vector<int>& b){
    vector<int> c(a.size()+b.size(),0);

    for(int i=0; i<a.size(); ++i){
        for(int j=0; j<b.size(); ++j){
            c[j+i]+= a[i]*b[j];
        }
    }

    // 进位操作
    int t= 0;
    for(int i=0; i<c.size(); ++i){
        t+= c[i];
        c[i]= t%10;
        t /=10;
    }

    // 去除前导0
    while(c.size()>1 && c.back()== 0 ) c.pop_back();

    return c;

}

int main(){
    string x, y;
    cin>> x>> y;

    for(int i= x.size()-1; i>=0; --i){ a.push_back(x[i]-'0'); }
    for(int i= y.size()-1; i>=0; --i){ b.push_back(y[i]-'0'); }

    vector<int> c= mul(a,b);

    for(int i= c.size()-1; i>=0; --i){
        cout<<c[i];
    }
}