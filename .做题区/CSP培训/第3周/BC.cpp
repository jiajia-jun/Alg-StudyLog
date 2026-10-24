#include<iostream>
#include<string>
using namespace std;

const int N= 100010;
char s[N];
int n, q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n>> q;
    for(int i=1; i<=n; ++i) cin>> s[i];

    for(int i=1; i<=q; ++i){
        int l, r;
        cin>> l>> r;
        int cnt= 0;
        for (int j = l; j < r; ++j){
            if (s[j] == 'A' && s[j+1] == 'C') cnt++;
        }
        cout<< cnt<< '\n';
    }
}