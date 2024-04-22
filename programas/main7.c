#include <stdio.h>

typedef struct {
    char nome[50];
    int ra;
    float n1, n2, med;
} ALUNO;

int main() {
    ALUNO aluno, *pAluno;
    
    pAluno = &aluno;

    printf("Nome do aluno: "); gets(pAluno->nome);
    printf("RA do aluno: "); scanf(" %d", &pAluno->ra);
    printf("Nota 1 do aluno: "); scanf(" %f", &pAluno->n1);
    printf("Nota 2 do aluno: "); scanf(" %f", &pAluno->n2);

    pAluno->med = (pAluno->n1 + pAluno->n2) / 2;

    printf("\nMedia do(a) aluno(a) %s (RA: %d): %.2f", pAluno->nome, pAluno->ra, pAluno->med);

    return 0;
}