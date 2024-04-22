#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10

typedef struct {
    char nome[40];
    int idade;
} PESSOA;

typedef struct {
    int ra;
    char nome[50];
    float n1, n2, med;
} ALUNO;

void mostrarPonteiro() {
    int x = 10, y = 20, *p1, *p2;

    p1 = &x;
    p2 = &y;

    printf("O valor de p1: %p\n", p1);
    printf("O conteudo de p1: %d\n", *p1);

    printf("\nO valor de p1: %p\n", p2);
    printf("O conteudo de p1: %d\n", *p2);

    *p1 = *p2; // equivalente a x = y
    printf("\nO valor de x: %d\n", x);
    printf("O valor de y: %d\n", y);

    p2 = p1; // atribui endereco de p1 em p2
    *p2 = 30;
    printf("\nO valor de x = %d\nO conteudo de p1 = %d", x, *p1);
}

void vetorPonteiro() {
    int i, vetor[max], *pvetor = NULL;

    pvetor = vetor;

    for (i = 0; i < max; i++) {
        *(pvetor + i) = i + 1;
    }

    for (i = 0; i < max; i++) {
        printf("O conteudo de pvetor[%d] = %d\n", i, *(pvetor + i));
    }
}

void calcularMedia() {
    srand(time(NULL));
    int i, vetor[max], *pvetor = NULL;
    float s = 0, med;

    pvetor = vetor;

    for (i = 0; i < max; i++) {
        *(pvetor + i) = rand() % 51;
        printf("Valor: %d\n", *(pvetor + i));
    }

    for (i = 0; i < max; i++) {
        s += *(pvetor + i);
    }

    med = s / max;

    printf("Media das idades = %.2f\n", med);
}

void structPonteiro() {
    PESSOA a, b, *pEstrutura;

    pEstrutura = &a;

    printf("Informe o nome: "); gets(pEstrutura -> nome);
    printf("Informe a idade: "); scanf("%d", &pEstrutura -> idade);

    strcpy(b.nome, pEstrutura -> nome);
    b.idade = pEstrutura -> idade;

    printf("Nome: %s\n", b.nome);
    printf("Idade: %d\n", b.idade);
}

void mostrarMediaEx() {
    ALUNO a, *pAluno;
    pAluno = &a;

    printf("Nome: "); gets(pAluno -> nome);
    printf("RA: "); scanf(" %d", &pAluno -> ra);
    printf("Nota 1: "); scanf(" %f", &pAluno -> n1);
    printf("Nota 2: "); scanf(" %f", &pAluno -> n2);

    pAluno->med = (pAluno->n1 + pAluno->n2) / 2;

    printf("\nMedia do aluno %s (RA: %d): %.2f", pAluno->nome, pAluno->ra, pAluno->med);
}

void mediaMaisAlunos() {
    int i;
    float medTotal = 0;
    ALUNO a[max], *pAluno = NULL;

    pAluno = a;

    for (i = 0; i < 2; i++) {
        printf("Nome do aluno %d: ", (i+1)); scanf(" %s", &(pAluno + i)->nome);
        printf("RA do aluno %d: ", (i+1)); scanf(" %d", &(pAluno + i)->ra);
        printf("Nota 1 do aluno %d: ", (i+1)); scanf(" %f", &(pAluno + i)->n1);
        printf("Nota 2 do aluno %d: ", (i+1)); scanf(" %f", &(pAluno + i)->n2);

        (pAluno+i)->med = ((pAluno+i)->n1 + (pAluno+i)->n2) / 2;

        printf("\n");
    }

    for (i = 0; i < 2; i++) {
        printf("\nMedia do(a) aluno(a) %s (RA: %d): %.2f", (pAluno+i)->nome, (pAluno+i)->ra, (pAluno+i)->med);
    }
    printf("\n");

    for (i = 0; i < 2; i++) {
        medTotal += (pAluno + i)->med;
    }
    printf("\nMedia total dos alunos: %f", (medTotal / 2));
}

void testeDePonteiro() {
    PESSOA a[2] = {
        {"Arthur", 20},
        {"Natallie", 24},
    }, *pa;
    pa = a;

    printf("%s", (pa + 1)->nome);
}

int main() {
    // mostrarPonteiro();
    // vetorPonteiro();
    // calcularMedia();
    // structPonteiro();
    // mostrarMediaEx();
    // mediaMaisAlunos();
    testeDePonteiro();

    return 0;
}