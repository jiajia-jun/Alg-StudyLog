#include<iostream>

using namespace std;

const int A= 10000;
const int B= 5000;
const int C= 1000;
int N, Y;
int a, b, c;

// a+b+c= N; 10a+5b+c=num;
bool judge(){
    int num= Y/C, t= 0;
    for(int i=0; i<=N; ++i){
        t= num- N- 4*i;
        if(t>=0 && t%9==0) {
            b= i, a= t/9;
            if(N-a-b<0) continue;
            else break;
        }
        if(i==N) return false;
    }
    c= N-a-b;
    return true;

}

int main(){
    cin>> N>> Y;
    if(judge()){
        printf("%d %d %d", a, b, c);
    }
    else printf("-1 -1 -1");
}