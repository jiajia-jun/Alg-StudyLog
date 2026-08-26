#include<iostream>

using namespace std;

const int N= 100010;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>> n;
    for(int i=1;i<=n;++i) cin>> a[i];

    int re=0;

    // i在左，j在右
    int i=1, j=n;
    int l_max=0, r_max=0;
    while(i != j){
        l_max = max(l_max, a[i]);
        r_max = max(r_max, a[j]);

        // 左侧最大高度小于右侧时，计算左侧接水
        if(l_max<=r_max) {
            re+= l_max-a[i];
            i++;
        }
        // 反之，计算右侧接水
        else if (l_max>r_max) {
            re+= r_max-a[j];
            j--;
        }
    }

    cout<< re<< '\n';
}
