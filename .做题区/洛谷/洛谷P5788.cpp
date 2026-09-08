#include<iostream>
#include<stack>
using namespace std;

const int N= 10000010;

int a[N];
stack<int> s, re;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>> n;
    for(int i=1; i<=n; ++i){
        cin>> a[i];
    }
    for(int i= n; i>0; --i){
        // 找右边第一个比他大的数
        while(!s.empty() && a[s.top()]<= a[i]){
            s.pop();
        }
        if(!s.empty()){
            re.push(s.top());
        }
        else re.push(0);
        s.push(i);
    }
    while(!re.empty()){
        cout<< re.top()<<' ';
        re.pop();
    }

}