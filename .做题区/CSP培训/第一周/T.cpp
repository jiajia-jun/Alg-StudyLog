#include<iostream>
#include<string>
using namespace std;

string s;
bool judge(){
    if(s[0]!= 'A') return false;
    int t= 0, f= 1;
    for(int i= 2; i<= s.length()-2; ++i){
        if(s[i]== 'C') {
            t++;
            continue;
        }
        if(s[i]<97) f= 0;
    }
    if(s[1]<97 || s[s.length()-1]<97 ) f= 0;
    if(t==1 && f) return true;
    return false;
}
int main(){
    cin>> s;
    if(judge()) cout<<"AC";
    else cout<<"WA";
}