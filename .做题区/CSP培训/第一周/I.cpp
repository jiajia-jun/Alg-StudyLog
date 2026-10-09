#include <iostream>
using namespace std;

int a, b, c, x, r;
int main() {
    cin>> a>> b>> c>> x;

    for (int i=0; i<= a; i++) {
        for (int j=0; j<= b; j++) {
            for (int k = 0; k<= c; k++) {
                if (500*i+ 100*j+ 50*k== x) {
                    r++;
                }
            }
        }
    }
    cout<< r;
    return 0;
}