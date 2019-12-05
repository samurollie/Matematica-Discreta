#include <bits/stdc++.h>

using namespace std;

int eh_primo (int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (!(n % i)) {
            return 0;
        }
    }
    return 1;
}

int proximo_primo(int n) {
    for (int i = n + 1;;i++) {
        if (eh_primo(i)) return i;
    }
}

int main () {
    int n;
    cin >> n;
    if (eh_primo(n)) {
        cout << n << " 1" << endl;
    } else {
        for(int i = 2; n > 1;) {
            if (n % i == 0) {
                cout << i << endl;
                n = n / i;
            } else {
                // printf ("%d\n", n);
                i = proximo_primo(i);
            }
        }
    }
    return 0;
}