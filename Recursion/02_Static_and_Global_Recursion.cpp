#include<bits/stdc++.h>
using namespace std;

int fun1(int n) {
    static int x = 0;
    if(n > 0) {
        // return fun1(n-1) + n;
        x++;
        return fun1(n-1) + x;
    }
    return 0;
}

int main() {
    int x = 5;
    cout << fun1(x);

    return 0;
}