#include <stdio.h>
#include <stdlib.h>
#define tam 10

typedef struct {
    int val[tam];
    int inicio, fim;
} FilaCircular;

typedef struct {
    int val[tam*2];
    int inicio, fim;
} FilaMaior;


char textosOpt[12][50] = {
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
    "Deu algum erro\n" // 11
};

/*
    <=== UTILITARIO ===>
*/
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
    <=== FUNCAO ===>
*/
void inicia(FilaCircular *fila) {
    fila->inicio = -1;
    fila->fim = -1;
}

int isCheia(FilaCircular *fila) {
    return ((fila->inicio == 0) && (fila->fim == tam - 1)) || (fila->inicio == fila->fim + 1);
}

int isVazia(FilaCircular *fila) {
    return fila->inicio == -1;
}

void insere(FilaCircular *fila, int value) {
    if (isCheia(fila)) {
        printf("Fila cheia. Nao eh possivel adicionar elementos\n");
        return;
    }
    if (isVazia(fila)) {
        fila->inicio = 0;
        fila->fim = 0;
    } else fila->fim = (fila->fim + 1) % tam;
    fila->val[fila->fim] = value;
    textoStatus(6);
}

int removeValor(FilaCircular *fila) {
    int removeValor;

    if (isVazia(fila)) {
        printf("Fila vazia. Nao eh possivel remover elementos\n");
        return -1;
    }
    removeValor = fila->val[fila->inicio];

    if (fila->inicio == fila->fim) {
        fila->inicio = -1;
        fila->fim = -1;
    } else fila->inicio = (fila->inicio + 1) % tam;

    return removeValor;
}

int totalElementos(FilaCircular *fila) {
    // printf("%d - %d\n", fila->inicio, fila->fim);
    int contador = 0;

    for (int i = fila->inicio; i != fila->fim; i = (i + 1) % tam) contador++;

    return ++contador;
}

void esvaziar(FilaCircular *fila) {
    if (!isVazia(fila)) {
        int limite = totalElementos(fila);
        for (int i = 0; i < limite; i++) removeValor(fila);
    }
}

void exibir(FilaCircular *fila) {
    int i;
    if (isVazia(fila)) {
        printf("Lista vazia\n");
        return;
    }

    for (i = fila->inicio; i != fila->fim; i = (i + 1) % tam) {
        printf("[%d] ", fila->val[i]);
    }
    printf("[%d]\n", fila->val[i]);
}

// funcoes para a FilaMaior
void inicia2(FilaMaior *fila) {
    fila->inicio = -1;
    fila->fim = -1;
}
int isCheia2(FilaMaior *fila) {
    return ((fila->inicio == 0) && (fila->fim == ((tam*2) - 1))) || (fila->inicio == fila->fim + 1);
}

int isVazia2(FilaMaior *fila) {
    return fila->inicio == -1;
}
void insere2(FilaMaior *fila, int value) {
    if (isCheia2(fila)) {
        printf("Fila cheia. Nao eh possivel adicionar elementos\n");
        return;
    }
    if (isVazia2(fila)) {
        fila->inicio = 0;
        fila->fim = 0;
    } else fila->fim = (fila->fim + 1) % (tam*2);
    fila->val[fila->fim] = value;
    textoStatus(6);
}
void exibir2(FilaMaior *fila) {
    int i;
    if (isVazia2(fila)) {
        printf("Lista vazia\n");
        return;
    }

    for (i = fila->inicio; i != fila->fim; i = (i + 1) % (tam*2)) {
        printf("[%d] ", fila->val[i]);
    }
    printf("[%d]\n", fila->val[i]);
}

FilaMaior * intercalar (FilaCircular *fila, FilaCircular *fila2, int tamF, int tamF2) {
    if (!isVazia(fila) && !isVazia(fila2)) {
        FilaMaior *filaRetorno = (FilaMaior *) malloc (sizeof(FilaMaior));
        inicia2(filaRetorno);

        if (tamF <= tamF2) {
            for (int i = 0; i < tamF; i++) {
                insere2(filaRetorno, removeValor(fila));
                insere2(filaRetorno, removeValor(fila2));
            }

            for (int i = 0; i < (tamF2 - tamF); i++) {
                insere2(filaRetorno, removeValor(fila2));
            }

        } else {
            for (int i = 0; i < tamF2; i++) {
                insere2(filaRetorno, removeValor(fila));
                insere2(filaRetorno, removeValor(fila2));
            }

            for (int i = 0; i < (tamF - tamF2); i++) {
                insere2(filaRetorno, removeValor(fila));
            }
        }

        return filaRetorno;
    } else {
        printf("Existem listas vazias");
        return NULL;
    }
}

/*
    <=== MENU ===>
*/
void opcao(FilaCircular *fila, int opcao) {
    int valor, retorno;
    switch (opcao) {
        case 0:
            break;
        case 1:
            valor = pegarValor(0);
            insere(fila, valor);
            break;
        case 2:
            retorno = removeValor(fila);
            if (retorno != -1) {
                textoStatus(7);
                printf("Valor removido: %d", retorno);
            }
            break;
        case 3:
            if (isCheia(fila)) printf("Lista esta cheia");
            else printf("Lista nao esta cheia");
            break;
        case 4:
            if (isVazia(fila)) printf("Lista esta vazia");
            else printf("Lista nao esta vazia");
            break;
        case 5:
            retorno = totalElementos(fila);
            printf("Total de elementos na lista: %d", retorno);
            break;
        case 6:
            esvaziar(fila);
            break;
        case 7:
            FilaCircular *fila2 = (FilaCircular *) malloc (sizeof(FilaCircular));
            FilaMaior *filaRetorno = (FilaMaior *) malloc (sizeof(FilaMaior));
            inicia(fila2);
            inicia2(filaRetorno);

            for (int i = 0; i < 5; i++) {
                insere(fila2, i + 1);
            } 

            filaRetorno = intercalar(fila, fila2, totalElementos(fila), totalElementos(fila2));
            exibir2(filaRetorno);
            break;
        case 99:
            exibir(fila);
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
            "1. Inserir valor na fila\n"
            "2. Remover valor na fila\n"
            "3. Verficar se a lista esta cheia\n"
            "4. Verificar se a lista esta vazia\n"
            "5. Total de elementos\n"
            "6. Esvaziar lista\n"
            "7. Intercalar\n"
            "99. Exibir\n"
            ">> ");
    scanf("%d", &opt);
    system("clear");
    return opt;
}

int main() {
    FilaCircular *fila = (FilaCircular *) malloc (sizeof(FilaCircular));
    int opt;

    inicia(fila);

    do {
        opt = menu();
        opcao(fila, opt);
    } while (opt);

    free(fila);
    return 0;
}
