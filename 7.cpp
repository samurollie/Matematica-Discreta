#include <bits/stdc++.h>

using namespace std;

int euclides (int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return euclides(b, a % b);
    }
}

int *extendedEuclid (int a, int b){
	int *dxy = (int *)malloc(sizeof(int) *3);

	if (b == 0){
		dxy[0] =a ; dxy[1] = 1; dxy[2] = 0;
		return dxy;
	} else {
		int t, t2;
		dxy = extendedEuclid(b, a % b);
		
        t = dxy[1];
		t2 = dxy[2];
		
        dxy[1] = dxy[2];
		dxy[2] = t - a/b *t2;
		return dxy;
	}
}

int main(){
	int a, b;
    cout << "Insira o valor de a e m: ";
    cin >> a >> b;

    if (euclides(a, b) != 1) {
        cout << "Como os numeros nao sao primos entre si, o inverso nao existe" << endl;
    } else {
        int *ptr;
        ptr = extendedEuclid (a, b);
        printf ("O inverso de %d mod %d eh %d\n", a, b, ptr[1]);
    }

	return 0;		
}