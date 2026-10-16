#include<iostream>
#include<string>
using namespace std;

const int N= 110;
char a[N];
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>> n;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
    }
    if(n%2==1){
        cout<< "No";
        return 0;
    }
    for(int i=1; i<=n/2; ++i){
        if(a[i]!=a[i+n/2]) {
            cout<< "No";
            return 0;
        }
    }
    cout<<"Yes";
}