#include <stdio.h>
#include <stdlib.h>

struct st_no {
    int valor;
    struct st_no *prox;
};

typedef struct st_no no;

// le > Lista Encadeada
int vazia(no *le) {
    // verifica se o proximo da lista eh NULL
    // se 1 a lista esta vazia
    if (le->prox == NULL) return 1;
    else return 0;
}

void inicia(no *le) {
    // inicializar a lista
    le->prox = NULL;
}

void libera(no *le) {
    // limpar a lista
    if (!vazia(le)) {
        no *proximoNo, *atual;
        atual = le->prox;
        
        while (atual != NULL) {
            // salva a info do proximo
            // limpa o valor atual
            // joga o "proximo" para o atual
            proximoNo = atual->prox;
            free(atual);
            atual = proximoNo;
        }
    }
}

void exibirLista(no *le) {
    if (vazia(le)) {
        printf("A lista esta vazia\n");
        return;
    }

    no *tmp;
    tmp = le->prox;

    while (tmp != NULL) {
        printf("%d ", tmp->valor);
        tmp = tmp->prox;
    }
    printf("\n");
}

void insereInicio(no *le) {
    no *novo = (no *) malloc (sizeof(no));
    if (!novo) {
        printf("Sem memoria disponivel\n");
        exit(1);
    }
    no *oldHead = le->prox;

    printf("Informe o valor: ");
    scanf("%d", &novo->valor);

    le->prox = novo;
    novo->prox = oldHead;

    // novo->prox = le;
    // le->prox = novo;
}

void insereFinal(no *le) {
    no *novo = (no *) malloc (sizeof(no));
    if (!novo) {
        printf("Sem memoria disponivel\n");
        exit(1);
    }

    printf("Informe o valor: ");
    scanf("%d", &novo->valor);

    novo->prox = NULL;
    
    if (vazia(le)) le->prox = novo;
    else {
        no *tmp = le->prox;

        while (tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
}

void exibirTeste(no *le) {
    printf("Valor: %d\nPonteiro: %p", &(le->valor), le->prox);
}

void opcao(no *le, int opcao) {
    switch (opcao) {
        case 0:
            libera(le);
            break;
        case 1:
            exibirLista(le);
            exibirTeste(le);
            break;
        case 2:
            insereInicio(le);
            break;
        case 3:
            insereFinal(le);
            break;
        case 4:
            inicia(le);
            break;
        default:
            printf("Comando invalido\n");
    }
}

int menu() {
    int opt;

    printf("\nOpcao\n"
            "0. Sair\n"
            "1. Exibir\n"
            "2. Inserir no inicio\n"
            "3. Inserir no final\n"
            "4. Zerar lista\n"
            ">> ");
    scanf("%d", &opt);
    system("cls");
    return opt;
}

int main() {
    no *le = (no *) malloc (sizeof(no));
    int opt;

    if (!le) {
        printf("Sem memoria disponivel\n");
        exit(1);
    }
    inicia(le);

    do {
        opt = menu();
        opcao(le, opt);
    } while (opt);
}
