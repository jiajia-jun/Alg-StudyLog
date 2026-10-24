#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string, int> m;
int n;

int main(){
    scanf("%d", &n);
    while(n--){
        string s;
        cin>> s;
        m[s]++;
    }
    printf("AC x %d\nWA x %d\nTLE x %d\nRE x %d",
    m["AC"], m["WA"], m["TLE"], m["RE"]);
}