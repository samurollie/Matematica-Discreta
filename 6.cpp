#include <bits/stdc++.h>

using namespace std;



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
    cout << "Insira o valor de a e b: ";
    cin >> a >> b;

    int *ptr;
	ptr = extendedEuclid (a, b);
	printf("%d = %d * %d + %d * %d \n", ptr[0], ptr[1], a, ptr[2], b);

	return 0;		
}