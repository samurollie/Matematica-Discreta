#include <bits/stdc++.h>

using namespace std;

struct fatores {
    int base;
    int expoente;
};

typedef vector<fatores> vf;

int eh_primo (int n) { // Verifica se um numero e primo
    for (int i = 2; i <= sqrt(n); i++) {
        if (!(n % i)) {
            return 0;
        }
    }
    return 1;
}

int proximo_primo(int n) { // Gera os numeros primos
    for (int i = n + 1;;i++) {
        if (eh_primo(i)) return i;
    }
}

vf adicionar (int n, vf f1) {
    int s = 0, i;
    for (i = 0; i < f1.size(); i++) { // Vejo se o meu numero ja foi adicionado;
        if (f1[i].base == n) {
            s = 1;
            break;
        }
    }
    if (s) { // Se eu ja adicionei aquele fator primo
        f1[i].expoente++;
    } else { // Se não, eu adiciono;
        fatores aux;
        aux.base = n;
        aux.expoente = 1;
        f1.push_back(aux);
    }
    return f1;
}

vf decompor (int n, vf f1) { // Decompõe um numero dado em fatores primos
    if (eh_primo(n)) { // Se o meu numero ja for um numero primo;
        fatores aux;
        aux.base = n;
        aux.expoente = 1;
        f1.push_back(aux);
    } else { // Se nao for um numero primo, eu vou decompor
        for(int i = 2; n > 1;) {
            if (n % i == 0) { // Se o meu primo for um divisor de n;
                f1 = adicionar(i, f1);
                n = n / i;
            } else {
                i = proximo_primo(i);
            }
        }
    }
    return f1;
}

int f (fatores a, fatores b) { // Funcao de comparacao
    return a.base > b.base;
}

vf adicionar_diferencas (vf a, vf b) { // Adiciona em b, os elementos q estão em a mas nao estão nele;
    for (int i = 0; i < a.size(); i++) { // Vejo se existem elementos de b que não estão em a
        int achou = 0; // Uma flag para indicar se achou ou nao;

        int begin = 0, end = b.size() - 1, mid;
        while (begin <= end) { // Faço uma busca binaria para ver se eu ja adicionei aquele fator primo;
            mid = (begin + end) / 2;
            if (a[i].base == b[mid].base) { // achei!
                achou++;
                break;
            } else if (b[mid].base > a[i].base) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        
        if (achou == 0) { // Se eu não achei
            fatores aux;
            aux.base = a[i].base;
            aux.expoente = 0;
            b.push_back(aux); // Eu salvo
        }
    }
    return b;
}

int mmc (vf a, vf b) {
    int s = 1;
    for (int i = 0; i < a.size(); i++) {
        s *= pow(a[i].base, min(a[i].expoente, b[i].expoente));
    }
    return s;
}

int mdc (vf a, vf b) {
    int s = 1;
    for (int i = 0; i < a.size(); i++) {
        s *= pow(a[i].base, max(a[i].expoente, b[i].expoente));
    }
    return s;
}

int main () {
    int n, m;
    cout << "Insira os dois numeros que deseja saber o mmc e o mdc: ";
    cin >> n >> m;
    
    vf f1, f2;
    f1 = decompor(n, f1);
    f2 = decompor(m, f2);

    sort(f1.begin(), f1.end(), f);
    sort(f2.begin(), f2.end(), f);
    
    f1 = adicionar_diferencas(f2, f1); // Adiciono em f1 os fatores de f2 que nao estao nele;
    f2 = adicionar_diferencas(f1, f2); // Adiciono em f2 os fatores de f1 que nao estão nele; 

    sort(f1.begin(), f1.end(), f);
    sort(f2.begin(), f2.end(), f);

    printf("MDC(%d,%d) = %d\n", n, m, mdc(f1, f2));
    printf("MMC(%d,%d) = %d\n", n, m, mmc(f1, f2));

    return 0;
}