#include<iostream>
using namespace std;

const int N= 1010;
int d[N][N];
int n, m;

void did(int &x1, int &y1, int &x2, int &y2){
    d[x1][y1]+= 1;
    d[x1][y2+1]-= 1;
    d[x2+1][y1]-= 1;
    d[x2+1][y2+1]+= 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n>> m;
    for(int i=1; i<=m; ++i){
        int a, b, c, dd;
        cin>> a>> b>> c>> dd;
        did(a, b, c, dd);
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            d[i][j]+= d[i-1][j]+d[i][j-1]- d[i-1][j-1];
        }
    }

    for(int i=1;i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cout<< d[i][j] <<' ';
        }
        cout<<'\n';
    }
}