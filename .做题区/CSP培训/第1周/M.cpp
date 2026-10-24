#include<iostream>
#include<string>
using namespace std;

int a, b, c;
bool judge(int x){
    string t= to_string(x);
    for(int i=0; i<t.length()/2; ++i){
        if(t[i]!=t[t.length()-i-1]) return false;
    }
    return true;
}
int main(){
    cin>> a>> b;
    for(int i=a; i<=b; ++i){
        if(judge(i)) c++;
    }
    cout<< c;
}