#include<iostream>
#include<string>
using namespace std;

string s;
int r;

int main(){
    cin>>s;
    for(char x:s){
        if(x=='1') r++;
    }
    cout<< r;
}