#include<iostream>
using namespace std;

double sum;
int n;

int main(){
    scanf("%d", &n);
    while(n--){
        int t;
        cin>> t;
        sum+= 1.0/t;
    }
    printf("%.8f", 1.0/sum);
}