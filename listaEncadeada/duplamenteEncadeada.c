#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *ante;
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
        if (tmp->ante != NULL) printf("%p <- ", tmp->ante);
        printf("%d -> %p\n", tmp->valor, tmp->prox);
        tmp = tmp->prox;
    }
    printf("NULL\n");
    printf("Inicio: %p <- %d -> %p\nFinal: %p <- %d -> %p\n", (*inicio)->ante, (*inicio)->valor, (*inicio)->prox, (*fim)->ante, (*fim)->valor, (*fim)->prox);
}

/*
    <=== FUNCOES ===>
*/

void insereInicio(Lista **inicio, Lista **fim, int valor) {
    Lista *novo = (Lista *) malloc (sizeof(Lista));
    hasMemory(&novo);
    novo->valor = valor;
    novo->ante = NULL;
    novo->prox = *inicio;

    if (*inicio == NULL) *fim = novo;
    else (*inicio)->ante = novo;

    *inicio = novo;
    textoStatus(6);
}

void insereFim(Lista **inicio, Lista **fim, int valor) {
    Lista *novo = (Lista *) malloc (sizeof(Lista));
    hasMemory(&novo);
    novo->valor = valor;
    novo->ante = *fim;
    novo->prox = NULL;

    if (*inicio == NULL) *inicio = novo;
    else (*fim)->prox = novo;

    *fim = novo;
    textoStatus(6);
}

void removeInicio(Lista **inicio, Lista **fim) {
    if (!vazia(inicio)) {
        Lista *tmp = *inicio;
        
        *inicio = tmp->prox;

        if (tmp->prox == NULL) *fim = NULL;
        else (*inicio)->ante = NULL;

        free(tmp);
        textoStatus(7);
    }
    textoStatus(3);
}

void removeFim(Lista **inicio, Lista **fim) {
    if (!vazia(inicio)) {
        Lista *tmp = *fim;

        *fim = tmp->ante;

        if (tmp->ante == NULL) *inicio = NULL;
        else (*fim)->prox = NULL;

        free(tmp);
        textoStatus(7);
    }
    textoStatus(3);
}

Lista * hasValor(Lista **inicio, int valor) {
    if (!vazia(inicio)) {
        Lista *tmp = *inicio;

        while (tmp != NULL) {
            if (tmp->valor == valor) {
                return tmp;
            }
            tmp = tmp->prox;
        }
        return NULL;
    }
    return NULL;
}

void insereAposNo(Lista **inicio, Lista **fim, int valor, int verif) {
    Lista *retorno = hasValor(inicio, verif);

    if (retorno != NULL) {
        Lista *novo = (Lista *) malloc (sizeof(Lista));
        hasMemory(&novo);
        novo->valor = valor;
        novo->ante = retorno;
        novo->prox = retorno->prox;

        retorno->prox = novo;

        if (*fim == retorno) *fim = novo;
        else novo->prox->ante = novo;

        textoStatus(6);
    } else insereFim(inicio, fim, valor);
}

int removeNoInformado(Lista **inicio, Lista **fim, int valor) {
    Lista *retorno = hasValor(inicio, valor);

    if (retorno != NULL) {
        if (retorno == *inicio) removeInicio(inicio, fim);
        else if (retorno == *fim) removeFim(inicio, fim);
        else {
            Lista *tmpAnte = retorno->ante;

            tmpAnte->prox = retorno->prox;
            retorno->prox->ante = tmpAnte;

            free(retorno);
        }

        return 1;
    } return 0;
}

/*
    <=== MENU ===>
*/
void opcao(Lista **inicio, Lista **fim, int opcao) {
    int valor, verif, retornoInt;
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
            if (retorno != NULL) {
                printf("Valor encontrado\n");
                if (retorno->ante != NULL) printf("%p <- ", retorno->ante);
                printf("%d -> %p", retorno->valor, retorno->prox);
            } else textoStatus(8);
            break;
        case 8:
            valor = pegarValor(0);
            verif = pegarValor(1);
            insereAposNo(inicio, fim, valor, verif);
            break;
        case 9:
            valor = pegarValor(0);
            retornoInt = removeNoInformado(inicio, fim, valor);
            if (retornoInt) textoStatus(7);
            else textoStatus(8);
            break;
        case 98:
            exibeValorEPonteiro(inicio, fim);
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
            "7. Verificar se o valor existe na lista\n"
            "8. Adicionar um valor após outro valor informado\n"
            "9. Excluir valor informado\n"
            "98. Exibe valor e ponteiro\n"
            "99. Ordenar lista\n"
            ">> ");
    scanf("%d", &opt);
    system("cls");
    return opt;
}

int main() {
    Lista *inicio = (Lista *) malloc (sizeof(Lista)),
        *fim = (Lista *) malloc (sizeof(Lista));
    int opt;

    hasMemory(&inicio);
    hasMemory(&fim);
    criar(&inicio, &fim);

    do {
        opt = menu();
        opcao(&inicio, &fim, opt);
    } while (opt);
}