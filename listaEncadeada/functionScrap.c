#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *prox;
};

typedef struct no Lista;

void ordenarListaPorPonteiro(Lista **le) {
    Lista *tmp = *le, *anterior, *placeholder = *le, *guardaValor;
    int contador = 0, isMenorValor = 0, isOrdenada = 0;

    while (tmp != NULL) {
        tmp = tmp->prox;
        contador++;
    }

    tmp = *le;

    for (int i = 0; i < contador; i++) {
        for (int j = 0; j < contador - i - 1; j++) {
            if (tmp->prox != NULL) {
                if (tmp->valor > (tmp->prox)->valor) {
                    guardaValor = tmp;

                    anterior = tmp->prox;
                    tmp->prox = anterior->prox; // nao muda o valor de tmp, tenho que comparar ele
                    anterior->prox = guardaValor;

                    // na primeira troca nao existe placeholder
                    if ((j == 0) && (isMenorValor == 0)) (*le) = anterior;
                    else placeholder->prox = anterior;
                                     
                    placeholder = anterior;
                } else {
                    tmp->prox = anterior->prox;
                }
            }
        }
        anterior->prox = tmp;

        tmp = *le;
        while (tmp->valor <= (tmp->prox)->valor) {
            isMenorValor = 1;
            placeholder = tmp;
            tmp = tmp->prox;
            if (tmp->prox == NULL) {
                isOrdenada = 1;
                break;
            }
        }
        if (isOrdenada) {
            // textoStatus(9);
            break;
        }
    }
}

void ordenarArray() {
    int a[3] = {4, 5, 3}, b;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                b = a[j];
                a[j] = a[j + 1];
                a[j + 1] = b;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("|%d|  ", a[i]);
    }
}

int main() {
    Lista *le;

    le = NULL;

    // ordenarListaPorPonteiro(&le);
    ordenarArray();
}
