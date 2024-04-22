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

void criar(Lista **inicio) {
    *inicio = NULL;
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

void libera(Lista **le) {
    if (!vazia(le)) {
        Lista *proximoNo, *atual, *guardaValor = *le;
        atual = *le;

        do {
            proximoNo = atual->prox;
            free(atual);
            atual = proximoNo;
        } while (atual != guardaValor);

        textoStatus(5);
    }
}

void exibeComPonteiro(Lista **le) {
    if (!vazia(le)) {
        Lista *tmp = *le, *guardaValor = *le;

        do {
            printf("%p <- %d -> %p\n", tmp->ante, tmp->valor, tmp->prox);
            tmp = tmp->prox;
        } while (tmp != guardaValor);
        printf("%p <- %d -> %p", tmp->ante, tmp->valor, tmp->prox);
    }
}

/*
    <=== FUNCOES ===>
*/
void exibe(Lista **le) {
    if (!vazia(le)) {
        Lista *tmp = *le, *guardaValor = *le;

        do {
            printf("|%d| -> ", tmp->valor);
            tmp = tmp->prox;
        } while (tmp != guardaValor);
        printf("|%d|", tmp->valor);
    } else printf("NULL");
}

void insereInicio(Lista **le, int valor) {
    Lista *novo = (Lista *) malloc (sizeof(Lista));
    hasMemory(&novo);

    novo->valor = valor;

    if (vazia(le)) {
        novo->ante = novo;
        novo->prox = novo;
    } else {
        novo->ante = (*le)->ante;
        novo->prox = *le;

        (*le)->ante->prox = novo;
        (*le)->ante = novo;
    }
    *le = novo;
    textoStatus(6);
}

void insereFim(Lista **le, int valor) {
    Lista *novo = (Lista *) malloc (sizeof(Lista));
    hasMemory(&novo);

    novo->valor = valor;

    if (vazia(le)) {
        novo->ante = novo;
        novo->prox = novo;
        *le = novo;
    } else {
        novo->ante = (*le)->ante;
        novo->prox = *le;

        (*le)->ante->prox = novo;
        (*le)->ante = novo;
    }
    textoStatus(6);
}

void removePrimeiro(Lista **le) {
    if (!vazia(le)) {
        Lista *tmp = *le;

        if (((*le)->prox == *le) && ((*le)->ante == *le)) criar(le);
        else {
            (*le)->prox->ante = (*le)->ante;
            (*le)->ante->prox = (*le)->prox;
            *le = (*le)->prox;
        }

        free(tmp);
        textoStatus(7);
    } else textoStatus(3);
}

void removeUltimo(Lista **le) {
    if (!vazia(le)) {
        Lista *tmp = (*le)->ante;

        if (((*le)->prox == *le) && ((*le)->ante == *le)) criar(le);
        else {
            tmp->ante->prox = *le;
            (*le)->ante = tmp->ante;
        }

        free(tmp);
        textoStatus(7);
    } else textoStatus(3);
}

/*
    <=== MENU ===>
*/
void opcao(Lista **le, int opcao) {
    int valor;
    switch (opcao) {
        case 0:
            libera(le);
            break;
        case 1:
            exibe(le);
            break;
        case 2:
            valor = pegarValor(0);
            insereInicio(le, valor);
            break;
        case 3:
            valor = pegarValor(0);
            insereFim(le, valor);
            break;
        case 4:
            removePrimeiro(le);
            break;
        case 5:
            removeUltimo(le);
            break;
        case 99:
            exibeComPonteiro(le);
            break;
        default:
            printf("Comando invalido\n");
            break;
    }
}

int menu() {
    int opt;

    printf("\n\nOpcao\n"
            "0. Sair\n"
            "1. Exibir\n"
            "2. Inserir no inicio\n"
            "3. Inserir no final\n"
            "4. Remover valor inicial\n"
            "5. Remover valor final\n"
            "99. Exibe com os ponteiros (debug)\n"
            ">> ");
    scanf("%d", &opt);
    system("cls");
    return opt;
}

int main() {
    Lista *inicio = (Lista *) malloc (sizeof(Lista));
    int opt;

    hasMemory(&inicio);
    criar(&inicio);

    do {
        opt = menu();
        opcao(&inicio, opt);
    } while (opt);
}
