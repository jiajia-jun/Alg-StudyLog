#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> a,b,c;

bool cmp(const string& a, const string& b){
    //先看位数，位数大的数字一定是大的
    if(a.size()!=b.size()){return a.size()>b.size();}
    //位数相同情况，再通过字典序比较（切忌直接比较）
    return a>b;
}

//为了方便起见，这里要确保 a >= b
void sub(vector<int>& a,vector<int>& b){
    //这一步是模拟减法的过程
    int t=0;
    for(int i=0;i<a.size();++i){
        t=a[i]-t;
        if(i<b.size()){
            t-=b[i];
        }
        c.push_back((t+10) % 10);
        if(t<0) t=1;
        else t=0;
    }
    //这一步是去除多余的0
    while(c.size()>1&&c.back()==0){
        c.pop_back();
    }
}

int main(){
    string x,y;
    cin>>x>>y;

    int al,bl;
    al=x.size();
    bl=y.size();

    //倒序存储
    for(int i=al-1;i>=0;--i){ a.push_back(x[i]-'0');}
    for(int i=bl-1;i>=0;--i){ b.push_back(y[i]-'0');}

    if(cmp(x,y)) sub(a,b);
    else {
        sub(b,a);
        cout<< '-';
    }

    for(int i=0;i<c.size();++i){
        cout<<c[c.size()-i-1];
    }
}
