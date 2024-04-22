#include <stdio.h>
#include <string.h>

void primeiras4Letras() {
    char *nome[50];

    printf("Informe o nome: ");
    scanf("%s", &nome);

    for (int i = 0; i < 4; i++) {
        printf("%c", nome[i]);
    }
};

void posicaoImparOuPar(int ver) {
    char *nome[50];

    printf("Informe o nome: ");
    scanf("%s", &nome);

    for (int i = 0; i < strlen(nome); i++) {
        if (!ver) {
            if (i % 2 == 0) {
                printf("%c", nome[i]);
            }
        } else {
            if (i % 2 != 0) {
                printf("%c", nome[i]);
            }
        }
    }
};

void imprimirNome() {
    char *nome[50];

    printf("Informe o nome: ");
    scanf("%s", &nome);

    for (int i = 0; i < 10; i++) {
        printf("%s\n", nome);
    }
};

void imprimirNomeTelEnd() {
    char *nome[50], *endereco[100];
    int telefone;

    printf("Informe o nome: ");
    scanf(" %[^\n]s", &nome);

    printf("Telefone: ");
    scanf("%d", &telefone);

    printf("Endereco: ");
    scanf(" %[^\n]s", &endereco);

    printf("Nome: %s\nTelefone: %d\nEndereco: %s", nome, telefone, endereco);
};

void seFeminino() {
    char sexo;
    int idade;

    printf("Informe o sexo (M/F ou m/f): ");
    scanf(" %c", &sexo);

    printf("Informe a sua idade: ");
    scanf("%d", &idade);

    if ((sexo == 'F' || sexo == 'f') && idade <= 25) {
        printf("ACEITA");
    } else printf("NAO ACEITA");
};

void letrasNoNome() {
    char nome[50];

    printf("Nome: ");
    scanf("%s", &nome);

    printf("%d", strlen(nome));
}

int main() {
    // primeiras4Letras();
    // posicaoImparOuPar(1);
    // imprimirNome();
    // imprimirNomeTelEnd();
    // seFeminino();
    // letrasNoNome();

    return 0;
}