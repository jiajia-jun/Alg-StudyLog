#include<iostream>
#include<string>
using namespace std;

int n, a, b, r;

bool cac(int num){
    string s= to_string(num);
    int sum= 0;
    for(char &x: s){
        sum+= x-48;
    }
    if(sum>= a&& sum<= b) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n>> a>> b;
    for(int i=1; i<=n; ++i){
        if(cac(i)) r+= i;
    }
    cout<< r;

}