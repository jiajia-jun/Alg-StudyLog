#include<iostream>
using namespace std;

int n, a;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>> n>> a;
    for(int i=a-n+1; i<a+n-1; ++i){
        cout<< i<< ' ';
    }
    cout<< a+n-1;
}