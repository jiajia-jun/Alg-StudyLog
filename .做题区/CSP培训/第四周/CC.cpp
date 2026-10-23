#include<iostream>
using namespace std;

int n, k;
int main(){
    cin>> n>> k;
    while(k--){
        if(n<10) n--;
        else{
            if(n%10==0) n/=10;
            else n--;
        }
    }
    cout<< n;
}