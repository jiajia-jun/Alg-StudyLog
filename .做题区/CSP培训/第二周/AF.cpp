#include<iostream>
#include<math.h>
using namespace std;

int x, r;
int main(){
    cin>> x;
    for(int i=1; i<=1000; ++i){
        for(int j=2; j<=9; ++j){
            int t= pow(double(i), double(j));
            if(t<=x) r=max(r, t);
            else break;
        }
    }
    cout<< r;
}