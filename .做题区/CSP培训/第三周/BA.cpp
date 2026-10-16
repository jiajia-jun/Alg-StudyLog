#include<iostream>
using namespace std;

const int N= 110;
int h, w;
int r[N], lh[N], l[N];
char m[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> h>> w;
    for(int i=1; i<=h; ++i){
        for(int j=1; j<=w; ++j){
            cin>> m[i][j];
            if(m[i][j]=='.') r[i]++, lh[j]++;
        }
        if(r[i]!=w) r[i]=0;
        else r[i]=1;
    }
    for(int j=1; j<=w; ++j){
        if(lh[j]!=h) l[j]=0;
        else l[j]=1;
    }

    for(int i=1; i<=h; ++i){
        if(r[i]) continue;
        for(int j=1; j<=w; ++j){
            if(l[j]) continue;
            cout<< m[i][j];
        }
        cout<<'\n';
    }
}