# KMP

KMP算法是一种以线性的时间复杂度进行字符串匹配的算法，它避免了传统的暴力算法  
（ps：这玩意真的晦涩难懂，花了我一个下午的时间才搞懂如何对小黄鸭解释整个算法）  
下面我们来看一个题：  
>给定长度为 n 的模板串p，和长度为 m 的主串s  
>要求我们输出主串 s 中能够完全匹配模板串 p 的下标开始和结束位置  
>(n <= 10^5   &&   m <= 10^6)

先提前说一嘴，KMP算法实际上包含两个部分（个人观点）：LPS（最长前后缀长度算法）部分和匹配部分  

下面我们先看代码实现（不建议单独啃），再来对两个部分进行讲解

```cpp
#include<iostream>
using namespace std;

const int N= 100010, M= 1000010;

char p[N], s[M];
int nxt[N], n, m;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;
    for(int i=1; i<=n; ++i) cin>> p[i];
    cin>> m;
    for(int i=1; i<=m; ++i) cin>> s[i];


//--------------------核心区分割线 1 LPC---------------------
    // nxt[]数组
    for(int i=2, j=0; i<=n; ++i){
        while(j!=0 && p[i] != p[j+1]){
            j= nxt[j];
        }
        if(p[i] == p[j+1]) j++;
        nxt[i] = j;
    }


//--------------------核心区分割线 2 匹配---------------------
    // 进行匹配
    int l=0, r=0;
    for(int i=1, j=0; i<=m; ++i){
        while(j!=0 && s[i]!= p[j+1]){
            j = nxt[j];
        }
        if(s[i]== p[j+1]) j++;
        if(j == n) {
            l= i-n, r= i-1; //0-base下标
            break;
        }
    }
    cout<< l <<' '<< r;
}
```

下面，我们先看一下匹配的机制，这样也方便LPC的理解

---
