/*
    Retorne a qtd de idades maiores e menores que 21
*/
#include <stdio.h>
#include <stdlib.h>

int *p, i;

void addIdades(int n) {
    for (i = 0; i < n; i++) {
        scanf("%d", (p + i));
    }
}

int maiorOuMenor(int n, int ver) {
    int qtd = 0;

    if (ver) {
        for (i = 0; i < n; i++) {
            if (*(p + i) >= 21) {
                qtd++;
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            if (*(p + i) < 21) {
                qtd++;
            }
        }
    }

    return qtd;
}

void maiorMenor2(int n, int *maior, int *menor) {
    for (i = 0; i < n; i++) {
        if (*(p + i) >= 21) (*maior)++;
        else (*menor)++;
    }
}

int main() {
    int n, qtdMaior, qtdMenor, maior = 0, menor = 0;

    puts("Qtd de idades: ");
    scanf("%d", &n);
    p = (int *) calloc (n, sizeof(int));
    addIdades(n);
    qtdMaior = maiorOuMenor(n, 1);
    qtdMenor = maiorOuMenor(n, 0);

    maiorMenor2(n, &maior, &menor);

    printf("Qtd de idades maior que 21: %d\n"
            "Qtd de idades menor que 21: %d", qtdMaior, qtdMenor);

    printf("\nQtd de idades maior que 21: %d\n"
            "Qtd de idades menor que 21: %d", maior, menor);

    return 0;
}