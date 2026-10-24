#include<iostream>
#include<string>
using namespace std;

string s;
int main(){
    cin>> s;
    for(char &x:s){
        cout<<'x';
    }
}