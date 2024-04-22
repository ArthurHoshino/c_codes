/*
    Ler um vetor e retornar a maior idade
*/
#include <stdio.h>
#include <stdlib.h>

int *p, i;

int comparar(const void * a, const void * b) {
    return ( *(int *)a - *(int *)b );
}

int maisVelho(int n) {
    int mv;

    for (i = 0; i < n; i++) {
        if (*(p + i) > mv) {
            mv = *(p + i);
        }
    }

    return mv;
}

void addIdades(int n) {
    puts("Digite as idades: ");
    for (i = 0; i < n; i++) {
        scanf("%d", (p + i));
    }
}

int main() {
    int n, m;

    puts("Digite a quantidade de idades: ");
    scanf("%d", &n);
    p = (int *) calloc (n, sizeof(int));
    addIdades(n);
    m = maisVelho(n);
    printf("Maior idade: %d", m);

    // with sort
    printf("\nBefore sorting the list: ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(p + i));
    }

    qsort(p, n, sizeof(int), comparar);

    printf("\nAfter sorting the list: ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(p + i));
    }

    printf("\nMaior idade: %d", *(p + n - 1));

    return 0;
}