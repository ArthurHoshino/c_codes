/*
    Arthur Osaka Hoshino: 635413
    Bruno Koji Nakao: 634905
    Fernando Manso Isaac: 634077
    Guilherme Silva Piantamar: 638205
*/
#include <stdio.h>

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
    "A lista esta cheia\n" // 3
    "Exibir lista\n", // 4
    "Lista zerada\n", // 5
    "Valor adicionado com sucesso\n", // 6
    "Valor removido com sucesso\n", // 7
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
        scanf("%c", &tipoSenha);

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
    if ( ( (*fila)->fim->senha % 1000 ) == 999 ) return 1;
    else return 0;
}

int isVazia(FilaSenha **fila) {
    if ((*fila)->prox == NULL) return 1;
    else return 0;
}

void adicionarFim(FilaSenha **fila) {
    if (!isCheia(fila)) {
        FilaSenha *novaSenha = (FilaSenha *) malloc (sizeof(FilaSenha));
        iniciar(&novaSenha);

        novaSenha->senha = (*fila)->fim->senha + 1;
        novaSenha->fim = NULL;

        if (isVazia(fila)) {
            novaSenha->prox = NULL;
            (*fila)->prox = novaSenha;
        } else (*fila)->fim->prox = novaSenha;

        (*fila)->fim = novaSenha;
    } else textoStatus(8);
}

void removerInicio(FilaSenha **fila) {
    if (!isVazia(fila)) {
        FilaSenha *tmp = *fila, *guardaValor = (*fila)->fim;

        while (tmp->prox != (*fila)->fim) tmp = tmp->prox;
        tmp->prox = NULL;

        free(guardaValor);
        (*fila)->fim = tmp;

    } else textoStatus(8);
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
            printf("\n");
        }
    }
}

/*
    <=== MENU ===>
*/
void opcao(FilaSenha **deficiente, FilaSenha **idoso, FilaSenha **gestante, FilaSenha **normal, int opcao) {
    char tipoSenha;
    switch (opcao) {
        case 0:
            break;
        case 1:
            tipoSenha = pegarTipoSenha();
            adicionarFim( (tipoSenha == 'D') ? deficiente : (tipoSenha == 'I') ? idoso : (tipoSenha == 'G') ? gestante : normal );
            break;
        case 2:
            tipoSenha = pegarTipoSenha();
            removerInicio( (tipoSenha == 'D') ? deficiente : (tipoSenha == 'I') ? idoso : (tipoSenha == 'G') ? gestante : normal );
            break;
        case 99:
            FilaSenha **filaArray[4] = {deficiente, idoso, gestante, normal};
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
            "99. Exibir\n"
            ">> ");
    scanf("%d", &opt);
    system("clear");
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

    do {
        opt = menu();
        opcao(filaDeficiente, filaIdoso, filaGestante, filaNormal, opt);
    } while (opt);
}