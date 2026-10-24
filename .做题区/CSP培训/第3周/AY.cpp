#include<iostream>
using namespace std;

int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    for(int i=0; i<=n/4; ++i){
        for(int j=0; j<=n/7; ++j){
            if(4*i+7*j== n){
                cout<< "Yes";
                return 0;
            }
        }
    }
    cout<< "No";
}