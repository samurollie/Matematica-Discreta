#include <bits/stdc++.h>

using namespace std;

int mdc (int a, int b) {
    return (b == 0) ? a : mdc(b, a % b);
}

int main () {
    int n, m;
    cin >> n >> m;
    cout << mdc(n, m) << endl;
    return 0;
}