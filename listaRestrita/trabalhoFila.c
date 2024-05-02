/*
    Arthur Osaka Hoshino: 635413
    Bruno Koji Nakao: 634905
    Fernando Manso Isaac: 634077
    Guilherme Silva Piantamar: 638205
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int senha;
    struct Node *prox;
    struct Node *fim;
};

typedef struct Node FilaSenha;


char textosOpt[10][50] = {
    "Informe o tipo da senha (D/I/G/N) >> ", // 0
    "Lista criada\n", // 1
    "A lista esta vazia\n", // 2
    "A lista esta cheia\n", // 3
    "Exibir lista\n", // 4
    "Lista zerada\n", // 5
    "Senha emitida\n", // 6
    "Cliente atendido\n", // 7
    "Deu algum erro\n" // 8
};

/*
    <=== UTILITARIO ===>
*/
void textoStatus(int opt) {
    printf("%s", textosOpt[opt]);
}

char pegarTipoSenha() {
    char tipoSenha;
    int sair = 1;
    textoStatus(0);
    
    do {
        scanf(" %c", &tipoSenha);

        if (tipoSenha == 'D' ||
            tipoSenha == 'I' ||
            tipoSenha == 'G' ||
            tipoSenha == 'N'
        ) {
            sair = 0;
        } else {
            textoStatus(8);
            textoStatus(0);
        }
    } while (sair);

    return tipoSenha;
}

/*
    <=== FUNCOES ===>
*/
void iniciar(FilaSenha **fila) { *fila = NULL; }

int isCheia(FilaSenha **fila) {
    if (*fila != NULL) {
        if ( (*fila)->fim->senha % 1000 == 999 ) return 1;
    }
    return 0;
}

int isVazia(FilaSenha **fila) {
    if (*fila == NULL) return 1;
    else return 0;
}

void adicionarFim(FilaSenha **fila, char tipoSenha) {
    if (!isCheia(fila)) {
        FilaSenha *novaSenha = (FilaSenha *) malloc (sizeof(FilaSenha));

        novaSenha->fim = NULL;
        novaSenha->prox = NULL;

        if (isVazia(fila)) {
            novaSenha->senha = (tipoSenha == 'D') ? 4000 : (tipoSenha == 'I') ? 3000 : (tipoSenha == 'G') ? 2000 : 1000;
            *fila = novaSenha;
        } else {
            novaSenha->senha = (*fila)->fim->senha + 1;
            (*fila)->fim->prox = novaSenha;
        }

        (*fila)->fim = novaSenha;
        textoStatus(6);
    } else textoStatus(8);
}

void removerInicio(FilaSenha **fila[4]) {
    for (int i = 0; i < 4; i++) {
        if (!isVazia(fila[i])) {
            FilaSenha *tmp = *fila[i];

            if (tmp->prox == NULL) iniciar(fila[i]);
            else {
                *fila[i] = tmp->prox;
                (*fila[i])->fim = tmp->fim;
            }

            free(tmp);
            textoStatus(7);
            return;
        }
    }
}

void exibir(FilaSenha **fila[4]) {
    for (int i = 0; i < 4; i++) {
        if (!isVazia(fila[i])) {
            FilaSenha *tmp = *fila[i];
            char letraSenha = (i == 0) ? 'D' : (i == 1) ? 'I' : (i == 2) ? 'G' : 'N';

            while (tmp != NULL) {
                printf("|%c%d| -> ", letraSenha, tmp->senha);
                tmp = tmp->prox;
            }
        }
    }
}

void limparLista(FilaSenha **fila[4]) {
    for (int i = 0; i < 4; i++) {
        if (!isVazia(fila[i])) {
            FilaSenha *tmp = *fila[i], *guardaValor;

            while (tmp != NULL) {
                guardaValor = tmp->prox;
                free(tmp);
                tmp = guardaValor;
            }
        }
    }
    textoStatus(5);
}

/*
    <=== MENU ===>
*/
void opcao(FilaSenha **filaArray[4], int opcao) {
    char tipoSenha;
    switch (opcao) {
        case 0:
            limparLista(filaArray);
            break;
        case 1:
            tipoSenha = pegarTipoSenha();
            adicionarFim( (tipoSenha == 'D') ? filaArray[0] : (tipoSenha == 'I') ? filaArray[1] : (tipoSenha == 'G') ? filaArray[2] : filaArray[3], tipoSenha );
            break;
        case 2:
            removerInicio(filaArray);
            break;
        case 3:
            exibir(filaArray);
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
            "1. Emitir senha\n"
            "2. Atender cliente\n"
            "3. Exibir\n"
            ">> ");
    scanf("%d", &opt);
    printf("\e[1;1H\e[2J");
    return opt;
}

int main() {
    FilaSenha *filaGestante = (FilaSenha *) malloc (sizeof(FilaSenha)),
    *filaDeficiente = (FilaSenha *) malloc (sizeof(FilaSenha)),
    *filaIdoso = (FilaSenha *) malloc (sizeof(FilaSenha)),
    *filaNormal = (FilaSenha *) malloc (sizeof(FilaSenha));
    int opt;
    
    iniciar(&filaDeficiente);
    iniciar(&filaIdoso);
    iniciar(&filaGestante);
    iniciar(&filaNormal);

    FilaSenha **filaArray[4] = {&filaDeficiente, &filaIdoso, &filaGestante, &filaNormal};

    do {
        opt = menu();
        opcao(filaArray, opt);
    } while (opt);
}