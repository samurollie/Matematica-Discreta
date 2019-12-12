#include <bits/stdc++.h>

using namespace std;

int main () {
    int a, b, m;
    cout << "Insira o valor de a: ";
    cin >> a;

    cout << "Insira o valor de b: ";
    cin >> b;
    
    cout << "Insira o valor de m: ";
    cin >> m;

    cout << "As soluções da congruência são: ";
    for (int i = 0; i < m; i++) {
        if ((a * i) % m == b) {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}