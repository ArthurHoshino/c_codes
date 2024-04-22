#include <stdio.h>
#define MAX 10

typedef struct {
    char nome[50];
    int ra;
    float n1, n2, med;
} ALUNO;

void alunoPonteiro1() {
    int i;
    float medTotal = 0;
    ALUNO aluno[10], *pAluno;
    
    pAluno = aluno; // passando a referencia do array, que sempre se inicializa em zero

    for (i = 0; i < MAX; i++) {
        printf("Nome do aluno %d: ", (i + 1)); scanf(" %s", &(pAluno + i)->nome);
        printf("RA do aluno %d: ", (i + 1)); scanf(" %d", &(pAluno + i)->ra);
        printf("Nota 1 do aluno %d: ", (i + 1)); scanf(" %f", &(pAluno + i)->n1);
        printf("Nota 2 do aluno %d: ", (i + 1)); scanf(" %f", &(pAluno + i)->n2);

        (pAluno + i)->med = ((pAluno + i)->n1 + (pAluno + i)->n2) / 2;

        medTotal += (pAluno + i)->med;
    }

    for (i = 0; i < MAX; i++) {
        printf("\nMedia do(a) aluno(a) %s (RA: %d): %.2f", (pAluno + i)->nome, (pAluno + i)->ra, (pAluno + i)->med);
    }

    printf("\nMedia total: %.2f", (medTotal / MAX));
};

void alunoPonteiro2() {
    int i;
    float medTotal = 0;
    ALUNO aluno[10], *pAluno;

    for (i = 0; i < MAX; i++) {
        pAluno = &aluno[i]; // passando a referencia de cada posicao

        printf("Nome do aluno %d: ", (i + 1)); scanf(" %s", &pAluno->nome);
        printf("RA do aluno %d: ", (i + 1)); scanf(" %d", &pAluno->ra);
        printf("Nota 1 do aluno %d: ", (i + 1)); scanf(" %f", &pAluno->n1);
        printf("Nota 2 do aluno %d: ", (i + 1)); scanf(" %f", &pAluno->n2);

        pAluno->med = (pAluno->n1 + pAluno->n2) / 2;
        medTotal = pAluno->med;
    }

    for (i = 0; i < MAX; i++) {
        printf("\nMedia do(a) aluno(a) %s (RA: %d): %.2f", pAluno->nome, pAluno->ra, pAluno->med);
    }

    printf("\nMedia total: %.2f", (medTotal / MAX));
};

int main() {
    // alunoPonteiro1();
    // alunoPonteiro2();

    return 0;
}