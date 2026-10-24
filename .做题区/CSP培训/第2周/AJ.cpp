#include<iostream>
#include<string>
using namespace std;

string s;
int r;

bool judge(char &c){
    return (c== 'A' || c=='G' || c=='C' || c=='T');
}

int main(){
    cin>> s;
    int t= 0;
    for(int i=0; i<(int)s.length(); ++i){
        if(judge(s[i])) r=max(r, ++t);
        else t= 0;
    }
    cout<< r;
}