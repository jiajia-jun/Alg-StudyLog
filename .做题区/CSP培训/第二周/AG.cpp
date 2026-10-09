#include<iostream>
using namespace std;

const int N= 1010;
int h[N];
int n, t, a, r;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n>> t>> a;
    int best= INT32_MAX;
    for(int i=1; i<=n; ++i) {
        cin>> h[i];
        int tmp= abs(1000*a-1000*t+h[i]*6);
        if(tmp<= best) {
            best= tmp;
            r= i;
        }
    }
    cout<< r;

}