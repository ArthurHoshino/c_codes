#include <stdio.h>
#include <stdlib.h>

int tamanho;

int* alocarVetor(int n) {
    int *p = (int *) calloc (n, sizeof(int));

    return p;
};

void lerValores(int *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("Informe o valor da posicao (%d): ", (i + 1));
        scanf("%d", (p + i));
    }
};

void mostrarValores(int *p, int n) {
    printf("Valores do vetor: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
}

void ordenar2(int *p, int n) {
    int a = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ( *(p + j) > *(p + j + 1) ) {
                a = *(p + j + 1);
                *(p + j + 1) = *(p + j);
                *(p + j) = a;
            }
        }
    }
}

int* intercalar(int *p, int *q) {
    int *a = (int *) calloc ((tamanho*2), sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        *(a + i * 2) = *(p + i);
        *(a + i * 2 + 1) = *(q + i);
    }

    return a;
}

int main() {
    int n, *p, *q, *r;

    puts("Tamanho do vetor: ");
    scanf("%d", &n);
    tamanho = n;

    p = alocarVetor(n);
    lerValores(p, n);
    mostrarValores(p, n);
    
    q = alocarVetor(n);
    lerValores(q, n);
    mostrarValores(q, n);

    ordenar2(p, n);
    ordenar2(q, n);

    r = intercalar(p, q);

    printf("\n");
    mostrarValores(r, n*2);

    return 0;
}