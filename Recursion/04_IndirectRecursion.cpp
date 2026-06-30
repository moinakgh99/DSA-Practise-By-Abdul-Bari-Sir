#include<bits/stdc++.h>
using namespace std;

void funA(int n);

void funB(int n) {
    if(n > 0) {
        cout << " " << n;
        funA(n/2);
    }
}

void funA(int n) {
    if(n > 0) {
        cout << " " << n;
        funB(n-1);
    }
}

int main() {
    int x = 20;
    funA(x);

    return 0;
}