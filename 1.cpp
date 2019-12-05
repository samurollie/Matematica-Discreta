#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;
    for (int i = 2; i <= sqrt(n); i++) {
        if (!(i % 2)) {
            cout << "Não é primo" << endl;
            return 0;
        }
    }
    if (n == 0 || n == 1) cout << "Não é primo" << endl;
    else cout << "É primo" << endl;
    return 0;
}