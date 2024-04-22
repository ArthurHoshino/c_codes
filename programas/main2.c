#include <stdio.h>

int main() {
    int n[10], maior, menor;

    for (int i = 0; i < 10; i++) {
        printf("Informe um numero: ");
        scanf("%d", &n[i]);

        if (i == 0) {
            maior = n[i];
            menor = n[i];
        }

        if (n[i] > maior) {
            maior = n[i];
        }
        if (n[i] < menor) {
            menor = n[i];
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", n[i]);
    }
    printf("\nMaior valor: %d\nMenor valor: %d", maior, menor);

    return 0;
}