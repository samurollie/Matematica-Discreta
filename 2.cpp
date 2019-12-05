#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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

void printar_primos() {
    int n = 1;
    for (;;) { 
        n = proximo_primo(n);
        cout << n << endl;
    }
}

int main () {
    int pid = fork();
    char cmd [500], id[500];

    if (pid <= -1) { // Se a criação do processo falhou
        perror("Error: ");
        exit (-1);

    } else if (pid >= 1) { // Se eu sou o processo pai;
        sprintf(id, "%d", pid); // Transforma o id do processo (int) em uma string;

        sleep(60); // Aguarda 60 segundos;

        strcpy(cmd, "kill ");
		strcat(cmd, id);
        system(cmd); // Mata o processo filho

    } else { // Se eu for o processo filho
        printar_primos();
    }
    return 0;
}