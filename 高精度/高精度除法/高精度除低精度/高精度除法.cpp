#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> a, c;

// a>= 0，b> 0
void mul(vector<int>& a, int b) {

    // t 的作用：1.余数 2.当前数位的除法结果 
    int t = 0;

    // a 是逆序存储，从最高位开始倒序遍历
    for (int i = a.size() - 1; i >= 0; --i) {
        t = t * 10 + a[i];
        c.push_back(t / b);
        t %= b;
    }

    // 此时结果是可能存在前导0的，为了方便去除前导0，这里反转一下c
    reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0) {
        c.pop_back();
    }

    // 恢复顺序，c是正常顺序了（这里可以选择不reverse，后面倒序输出就好了）
    reverse(c.begin(), c.end());  
}

int main() {
    string x;
    cin >> x;

    // 逆序存储（其实这里可以用正序的，稍微改一点代码就好了，
    //只不过方便记忆，高精度算法就统一用逆序算了）
    for (int i = x.size() - 1; i >= 0; --i) {
        a.push_back(x[i] - '0');
    }

    int b;
    cin >> b;

    mul(a, b);

    for (int i = 0; i < c.size(); ++i) {
        cout << c[i];
    }

    return 0;
}