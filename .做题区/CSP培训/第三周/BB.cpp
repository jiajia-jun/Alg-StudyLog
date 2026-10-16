#include<iostream>
#include<set>
using namespace std;

const int N= 1000010;
int a[N], s;
set<int> st;

int func(int x){
    if(x%2==0){
        return x/=2;
    }
    else return 3*x+1;
}

int main(){
    cin>> a[1];
    st.insert(a[1]);
    for(int i=2; i<=1000000;++i){
        a[i]=func(a[i-1]);
        if(st.count(a[i])){
            cout<< i;
            return 0;
        }
        st.insert(a[i]);
    }
}