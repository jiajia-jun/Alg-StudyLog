#include<iostream>

using namespace std;

const int N= 1000010;

int p[N];

int find(int x){
    if(p[x]!= x) p[x]= find(p[x]);
    return p[x]; 
}

int main(){
    int n, m;
    cin>> n>> m;
    for(int i=1; i<= n; ++i){
        p[i]= i;
    }
    while(m--){
        int z, x, y;
        cin>> z>> x>> y;
        if(z == 1){
            // y作为新的根节点合并
            p[find(x)] = find(y);
        }
        else if(z == 2){
            if(find(x)== find(y)){
                cout<< "Y\n";
            }
            else cout<< "N\n";
        }
    }
}