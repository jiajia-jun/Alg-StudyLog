#include<iostream>
using namespace std;

int a, b, r;
int q[5];
int main(){
    cin>> a>> b;
    if(a==1 || b==1) q[1]=1;
    if(a==2 || b==2) q[2]=1;
    if(a==3 || b==3) q[1]=q[2]=1;
    if(a==4 || b==4) q[4]=1;
    if(a==5 || b==5) q[1]=q[4]=1;
    if(a==6 || b==6) q[2]=q[4]=1;
    if(a==7 || b==7) q[1]=q[2]=q[4]=1;
    for(int i=1; i<=4; ++i){
        if(q[i]) r+= i;
    }
    cout<< r;
}