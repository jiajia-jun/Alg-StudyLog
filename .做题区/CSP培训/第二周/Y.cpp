#include<iostream>
#include<string>
using namespace std;

const int N= 30;
int c[N];
char r= 123;
string s;

int main(){
    cin>> s;
    for(char &x:s){
        c[x-'a']= 1;
    }
    for(int i=0; i<26; ++i){
        if(c[i]== 0) r= min((int)r, i+ 'a');
    }
    
    if(r== 123) cout<<"None";
    else cout<< r;
}