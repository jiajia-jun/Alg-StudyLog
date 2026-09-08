#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<int> x, y;

int com(float n){
    return round(n);
}

int bank(float n){
    int a= floor(n);
    int b= 10*n-10*a;
   // cout<<a<<' '<<b<<'\n';
    if(b != 5) return com(n);
    else{
        if(a%2==0) return a;
        return a+1;
    }
}

int main(){
    int n;
    cin>> n;
    while(n--){
        float num;
        cin>> num;
        x.push_back(com(num));
        y.push_back(bank(num));
    }
    for(auto i:x){
        cout<< i<< ' ';
    }
    cout<<'\n';
    for(auto i:y){
        cout<< i<< ' ';
    }
}
