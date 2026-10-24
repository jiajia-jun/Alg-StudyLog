#include<iostream>
#include<string>
using namespace std;

int n;
int d[6]={0, 9, 0, 909, 0, 90909};

int ten(int x){
    int r=1;
    while(x--) r*=10;
    return r;
}

int cac(){
    string s= to_string(n);
    int c= s.length(); // 位数

    if(c == 1){ // 1位数特判
        return (n-1)%n+1;
    }
    else {
        if(c>=2 && c%2){ // 位数大于2且位数为奇数
            return (n-ten(c-1))%n+1+d[c-2];
        }

        return d[c-1]; // 偶数位情况
    }
}

int main(){
    cin>> n;
    cout<< cac();
}