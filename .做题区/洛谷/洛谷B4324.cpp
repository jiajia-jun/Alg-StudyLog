#include<iostream>

using namespace std;

const int N= 1000010;

int l[N], r[N];
bool d[N];

void ins_r(int y, int x){
    if(x == y) return;
    // 如果节点存在原数组中，先删除原关系
    if(!d[x]){
        r[l[x]]=r[x];
        l[r[x]]=l[x];
    }
    // 新的插入操作
    l[x]= y, r[x]= r[y];
    l[r[y]]= x, r[y]= x;
}

void del(int x){
    if(d[x]) return;
    r[l[x]]=r[x];
    l[r[x]]=l[x];
    d[x]= 1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>> n>> m;
    // 初始化链表
    r[0]= 1, l[n+1]=n;
    l[0]= 0, r[n+1]=0;
    for(int i=1; i<=n;++i){
        l[i]= i-1;
        r[i]= i+1;
    }
    while(m--){
        int op;
        cin>> op;
        if(op == 1){
            int x,y;
            cin>> x>> y;
            ins_r(l[y], x);
        }
        else if(op == 2){
            int x, y;
            cin>> x>> y;
            ins_r(y, x);
        }
        else if(op == 3){
            int x;
            cin>> x;
            del(x);
        }
    }

    bool emp = true;
    for(int i=r[0]; i!= n+1; i= r[i]){
        if(!d[i]) {
            emp = false;
            cout<< i <<' ';
        }
    }
    if(emp) cout<< "Empty!";
}