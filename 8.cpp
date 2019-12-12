#include <bits/stdc++.h>

using namespace std;

int euclides (int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return euclides(b, a % b);
    }
}

int main () {
    int a, b, m;
    cout << "Insira o valor de a: ";
    cin >> a;

    cout << "Insira o valor de b: ";
    cin >> b;
    
    cout << "Insira o valor de m: ";
    cin >> m;

    int d = euclides(a, m);
    if (b % d != 0) {
        cout << "A congruência não possui soluçao" << endl;
        return 0;
    }
    
    cout << "As " << d << " soluções da congruência são: ";
    for (int i = 0; i < m; i++) {
        if ((a * i) % m == b) {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}
