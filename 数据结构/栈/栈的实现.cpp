#include<iostream>
#include<string>
using namespace std;

const int N = 100010;

int t = -1; // t用来记录栈顶(top)情况，-1表示栈空
int stk[N];

// 压入栈顶
void push(int x) {
    stk[++t] = x;
}

// 判空
bool empty() {
    return t == -1;
}

// 弹出栈顶元素
void pop() {
    t--;
}

// 返回栈顶元素
int top(){
    return stk[t];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin>> m;
    while(m--){
        int x;
        string q;
        cin>> q;
        if(q == "push"){
            cin>> x;
            push(x);
        }
        else if(q == "pop"){
            pop();
        }
        else if(q == "empty"){
            if(empty()) cout<< "YES"<< '\n';
            else cout<< "NO"<< '\n';
        }
        else if(q == "query"){
            cout<< top()<< '\n';
        }
    }
}
