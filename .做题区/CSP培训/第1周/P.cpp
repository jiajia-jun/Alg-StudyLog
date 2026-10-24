#include<iostream>
using namespace std;

int a, b, c;
int main(){
    cin>> a>> b>> c;
    if(c-a<= b && c-a>= 0) cout<< "YES";
    else cout<< "NO";
}