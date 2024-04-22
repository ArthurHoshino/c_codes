#include <stdio.h>

int main() {
    int a;

    printf("Informe um numero de 1 a 3: ");
    scanf("%d", &a);

    switch(a) {
        case 1:
            printf("Numero 1");
            break;
        case 2:
            printf("Numero 2");
            break;
        case 3:
            printf("Numero 3");
            break;
        default:
            printf("Nao eh 1, nem 2 ou 3 =)");
            break;
    }

    return 0;
}