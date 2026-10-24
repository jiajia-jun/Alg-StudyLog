#include<iostream>
using namespace std;

int a, b, c, d;
bool judge(){
    return (c+b-1)/b <= (a+d-1)/d;
}

int main(){
    cin>> a>> b>> c>> d;
    if(judge()) cout<<"Yes";
    else cout<< "No";
}