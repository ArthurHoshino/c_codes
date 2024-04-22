#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *prox;
};

typedef struct no Lista;

char textosOpt[11][50] = {
    "Informe o valor >> ", // 0
    "Valor para verificar >> ", // 1
    "Lista criada\n", // 2
    "A lista esta vazia\n", // 3
    "Exibir lista\n", // 4
    "Lista zerada\n", // 5
    "Valor adicionado com sucesso\n", // 6
    "Valor removido com sucesso\n", // 7
    "Valor nao existe na lista\n", // 8
    "Lista ordenada com sucesso\n", // 9
    "Valor movido com sucesso\n", // 10
};

/*
    <=== UTILITARIOS ===>
*/

void criar(Lista **inicio, Lista **fim) {
    *inicio = NULL;
    *fim = NULL;
}

int vazia(Lista **le) {
    if (*le == NULL) return 1;
    else return 0;
}

void hasMemory(Lista **le) {
    if (!*le) {
        printf("Sem memoria\n");
        exit(1);
    }
}

void textoStatus(int opt) {
    printf("%s", textosOpt[opt]);
}

int pegarValor(int opt) {
    int v = 0;
    textoStatus(opt);
    scanf("%d", &v);

    return v;
}

/*
    <=== FUNCOES ===>
*/

void exibe(Lista **inicio) {
    Lista *tmp;
    tmp = *inicio;

    while (tmp != NULL) {
        printf("|%d| -> ", tmp->valor);
        tmp = tmp->prox;
    }
    printf("NULL\n");
}

void exibeValorEPonteiro(Lista **inicio, Lista **fim) {
    if (vazia(inicio)) {
        textoStatus(3);
        return;
    }
    Lista *tmp = *inicio;

    while (tmp != NULL) {
        printf("%d -> %p\n", tmp->valor, tmp->prox);
        tmp = tmp->prox;
    }
    printf("NULL\n");
    printf("Inicio: %d -> %p\nFinal: %d -> %p\n", (*inicio)->valor, (*inicio)->prox, (*fim)->valor, (*fim)->prox);
}

void libera(Lista **inicio) {
    if (!vazia(inicio)) {
        Lista *proximoNo, *atual;
        atual = *inicio;

        while (atual != NULL) {
            proximoNo = atual->prox;
            free(atual);
            atual = proximoNo;
        }

        textoStatus(5);
    }
}

void insereInicio(Lista **inicio, Lista **fim, int valor) {
    Lista *tmp = (Lista *) malloc (sizeof(Lista));
    hasMemory(&tmp);

    tmp->valor = valor;
    tmp->prox = *inicio;

    if (*inicio == NULL) *fim = tmp;
    *inicio = tmp;
}

void insereFim(Lista **inicio, Lista **fim, int valor) {
    Lista *tmp = (Lista *) malloc (sizeof(Lista));
    hasMemory(&tmp);

    tmp->valor = valor;
    tmp->prox = NULL;

    if (*inicio == NULL) *inicio = tmp;
    else (*fim)->prox = tmp;

    *fim = tmp;
}

int removeInicio(Lista **inicio, Lista **fim) {
    if (*inicio != NULL) {
        Lista *tmp = *inicio;
        *inicio = tmp->prox;

        if (tmp == *fim) *fim = NULL;

        free(tmp);
        return 1;
    }
    return 0;
}

int removeFim(Lista **inicio, Lista **fim) {
    if (*inicio != NULL) {
        Lista *tmp = *fim, *q;

        if (tmp == *inicio) {
            *inicio = NULL;
            *fim = NULL;
        } else {
            q = *inicio;

            while (q->prox != tmp) q = q->prox;
            q->prox = NULL;
            *fim = q;
        }

        free(tmp);
        return 1;
    }
    return 0;
}

Lista * hasValor(Lista **inicio, int valor) {
    Lista *tmp = *inicio;

    if (!vazia(&tmp)) {
        while (tmp->valor != valor) {
            tmp = tmp->prox;

            if (tmp == NULL) {
                return NULL;
            }
        }

        return tmp;
    } else return NULL;
}

void jogaInicio(Lista **inicio, Lista **fim, int valor) {
    Lista *retorno = hasValor(inicio, valor);

    if ((retorno != NULL) && (retorno != *inicio)) {
        Lista *anterior = *inicio;
        
        while (anterior->prox != retorno) anterior = anterior->prox;
        anterior->prox = retorno->prox;

        if (retorno == *fim) (*fim) = anterior;

        retorno->prox = *inicio;
        *inicio = retorno;

        textoStatus(10);
    } else textoStatus(8);
}

void jogaFim(Lista **inicio, Lista **fim, int valor) {
    Lista *retorno = hasValor(inicio, valor);

    if ((retorno != NULL) && (retorno != *fim)) {
        Lista *anterior = *inicio;

        if (retorno != *inicio) {
            while (anterior->prox != retorno) anterior = anterior->prox;
            anterior->prox = retorno->prox;
        } else *inicio = retorno->prox;

        retorno->prox = NULL;

        (*fim)->prox = retorno;
        *fim = retorno;

        textoStatus(10);
    } else textoStatus(8);
}

void ordenarLista(Lista **inicio, Lista **fim) {
    Lista *tmp = *inicio;
    int contador = 0, tmpValue;

    while (tmp != NULL) {
        contador++;
        tmp = tmp->prox;
    }
    tmp = *inicio;

    for (int i = 0; i < contador; i++) {
        for (int j = 0; j < contador - i - 1; j++) {
            if (tmp->prox != NULL) {
                if (tmp->valor > tmp->prox->valor) {
                    tmpValue = tmp->valor;
                    tmp->valor = tmp->prox->valor;
                    tmp->prox->valor = tmpValue;
                }
                tmp = tmp->prox;
            }
        }
        tmp = *inicio;
    }

    while (tmp->prox != NULL) tmp = tmp->prox;
    *fim = tmp;

    textoStatus(9);
}

/*
    <=== MENU ===>
*/

void opcao(Lista **inicio, Lista **fim, int opcao) {
    int valor;
    Lista *retorno;
    switch (opcao) {
        case 0:
            libera(inicio);
            break;
        case 1:
            exibe(inicio);
            break;
        case 2:
            valor = pegarValor(0);
            insereInicio(inicio, fim, valor);
            break;
        case 3:
            valor = pegarValor(0);
            insereFim(inicio, fim, valor);
            break;
        case 4:
            criar(inicio, fim);
            break;
        case 5:
            removeInicio(inicio, fim);
            break;
        case 6:
            removeFim(inicio, fim);
            break;
        case 7:
            valor = pegarValor(0);
            retorno = hasValor(inicio, valor);
            if (retorno != NULL) printf("Valor encontrado, ponteiro: %p", &(retorno->valor));
            else printf("Valor nao encontrado");
            break;
        case 8:
            valor = pegarValor(0);
            jogaInicio(inicio, fim, valor);
            break;
        case 9:
            valor = pegarValor(0);
            jogaFim(inicio, fim, valor);
            break;
        case 98:
            exibeValorEPonteiro(inicio, fim);
            break;
        case 99:
            ordenarLista(inicio, fim);
            break;
        default:
            printf("Comando invalido\n");
    }
}

int menu() {
    int opt;

    printf("\n\nOpcao\n"
            "0. Sair\n"
            "1. Exibir\n"
            "2. Inserir no inicio\n"
            "3. Inserir no final\n"
            "4. Zerar lista\n"
            "5. Remover o primeiro valor\n"
            "6. Remover o ultimo valor\n"
            "7. Verificar se tem o valor na lista\n"
            "8. Jogar o valor informado para o inicio se ele existir\n"
            "9. Jogar o valor informado para o final se ele existir\n"
            "98. Exibe valor e ponteiro\n"
            "99. Ordenar lista\n"
            ">> ");
    scanf("%d", &opt);
    system("cls");
    return opt;
}

int main() {
    Lista *inicio, *fim;
    int opt;

    criar(&inicio, &fim);

    do {
        opt = menu();
        opcao(&inicio, &fim, opt);
    } while (opt);

    return 0;
}
