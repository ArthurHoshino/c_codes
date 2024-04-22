/*
    Pessoas de idade maior ou igual a media das idades
*/
#include <stdio.h>
#include <stdlib.h>

int *p, *retorno, i;

void addIdades(int n) {
    puts("Digite as idades: ");
    for (i = 0; i < n; i++) {
        scanf("%d", (p + i));
    }
}

int media(int n) {
    int s;

    for (i = 0; i < n; i++) {
        s += *(p + i);
    }

    return s/n;
}

void verificacao(int n, int med, int *maior, int *menor) {
    for (i = 0; i < n; i++) {
        if (*(p + i) >= med) (*maior)++;
        else (*menor)++;
    }
}

void maiorDe21(int n, int *maior) {
    int j = 0;
    for (i = 0; i < n; i++) {
        if (*(p + i) >= 21) {
            (*maior)++;
        }
    }

    retorno = (int *) calloc ((*maior), sizeof(int));

    for (i = 0; i < n; i++) {
        if (*(p + i) >= 21) {
            *(retorno + j) = *(p + i);
            j++;
        }
    }
}

int main() {
    int n, maior = 0, menor = 0, maiorIgual21 = 0;
    float med;

    puts("Total de idades: ");
    scanf("%d", &n);
    p = (int *) calloc (n, sizeof(int));
    addIdades(n);
    med = media(n);
    verificacao(n, med, &maior, &menor);

    printf("Media: %.2f\n"
            "Qtd maior/igual a media: %d\n"
            "Qtd menor que a media: %d\n", med, maior, menor);

    maiorDe21(n, &maiorIgual21);
    for (i = 0; i < maiorIgual21; i++) {
        printf("%d ", *(retorno + i));
    }

    return 0;
}