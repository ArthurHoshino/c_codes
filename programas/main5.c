// Struct e uso de referencia
#include <stdio.h>

struct aluno {
    char *nome[50];
    int *idade;
};

void trocaIdade(int *i) {
    *i = 5;
}

int main() {
    struct aluno a1;

    printf("Nome e idade: ");
    scanf("%s %d", &a1.nome, &a1.idade);

    printf("%s, %d", a1.nome, a1.idade);
    trocaIdade(&a1.idade);
    printf("%s, %d", a1.nome, a1.idade);

    return 0;
}