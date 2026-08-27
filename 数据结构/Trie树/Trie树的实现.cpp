#include<iostream>
#include<string>
using namespace std;

const int N= 100010;


// trie[][]用于存储树的结构，idx用于分配子节点编号（0为根部节点）
// cnt[]统计以每个节点结尾的字符串数量
int trie[N][26];
int cnt[N],idx ;

void ins(const string& s){
    int p= 0; // 父节点编号
    for(char c: s){
        // 先把字符映射为数字，'a'为 0
        int m = c- 'a';
        
        // trie[p][m] = idx的含义：
        // 编号为 p的父节点，指向一个编号为 idx的、映射值为 m的子节点
        if(!trie[p][m]){ // 如果子节点是空的
            trie[p][m]= ++idx ; // 创建子节点并分配编号
        }
        // 父节点变成当前新出现的子节点，进入下一个字符的连接
        p = trie[p][m];
    }
    cnt[p]++;
}

int query(const string& s){
    int p= 0;
    for(char c: s){
        int m = c- 'a';
        // 查询到字符不存在，则直接返回 0
        if(!trie[p][m]){
            return 0;
        }
        // 继续更新父节点
        p = trie[p][m];
    }
    return cnt[p];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>> n;
    while(n--){
        string d, s;
        cin>> d>> s;
        if(d == "I"){
            ins(s);
        }
        if(d == "Q"){
            cout<< query(s)<< '\n';
        }
    }
    return 0;
}