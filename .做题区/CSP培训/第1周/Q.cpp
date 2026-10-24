#include<iostream>
using namespace std;

int a, b, c;
int main(){
    cin>> a>> b;
    c= max(max(a+b, a-b), a*b);
    cout<< c;
}