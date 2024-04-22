#include <stdio.h>
#include <stdlib.h>

struct st_no {
    int valor;
    struct st_no *prox;
};

typedef struct st_no Lista;

char textosOpt[10][50] = {
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
};

/*
    <==== UTILITARIOS ===>
*/
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
// acho que sao duas formas de criar a lista...?
Lista * criar() {
    return NULL;
}

void cria (Lista **le) {
    *le = NULL;
    textoStatus(2);
}

void exibe(Lista **le) {
    if (vazia(le)) {
        textoStatus(3);
        return;
    }
    textoStatus(4);
    Lista *tmp;
    tmp = *le;
    
    while (tmp != NULL) {
        printf("|%d| -> ", tmp->valor);
        tmp = tmp->prox;
    }
    printf("NULL\n");
}

void libera(Lista **le) {
    // limpar a lista
    if (!vazia(le)) {
        Lista *proximoNo, *atual;
        atual = *le;
        
        while (atual != NULL) {
            // salva a info do proximo
            // limpa o valor atual
            // joga o "proximo" para o atual
            proximoNo = atual->prox;
            free(atual);
            atual = proximoNo;
        }
        textoStatus(5);
    }
}

void insereInicio(Lista **le, int value) {
    Lista *novo = (Lista *) malloc (sizeof(Lista));

    hasMemory(&novo);

    novo->valor = value;
    novo->prox = *le;

    (*le) = novo;
    textoStatus(6);
}

void insereFim(Lista **le, int value) {
    Lista *velho, *novo = (Lista *) malloc (sizeof(Lista));
    
    hasMemory(&novo);

    novo->valor = value;
    novo->prox = NULL;

    if (vazia(le)) *le = novo;
    else {
        velho = *le;
        
        while (velho->prox != NULL) velho = velho->prox;
        velho->prox = novo;
    }
    textoStatus(6);
}

void removeInicio(Lista **le) {
    if (vazia(le)) {
        textoStatus(3);
        return;
    }
    Lista *valorPraZerar = *le;
    *le = valorPraZerar->prox;

    free(valorPraZerar);
    textoStatus(7);
}

void removeFim(Lista **le) {
    if (vazia(le)) {
        textoStatus(3);
        return;
    }
    Lista *tmp = *le, *anterior;

    while (tmp->prox != NULL) {
        anterior = tmp;
        tmp = tmp->prox;
    }
    free(tmp);
    anterior->prox = NULL;
    textoStatus(7);
}

Lista * retornaValor(Lista **le, int valor) {
    Lista *tmp = *le;

    while ((tmp != NULL) && (tmp->valor != valor)) {
        tmp = tmp->prox;
    }

    return (tmp);
}

void adicionarNaFrenteDoNo(Lista **le, int valor, int verif) {
    Lista *retorno = retornaValor(le, verif);

    if (retorno != NULL) {
        Lista *tmp = (Lista *) malloc (sizeof(Lista));
        hasMemory(&tmp);
        tmp->valor = valor;
        tmp->prox = retorno->prox;

        retorno->prox = tmp;
        textoStatus(6);
    } else textoStatus(8);
}

void adicionarAntesDoNo(Lista **le, int valor, int verif) {
    Lista *retorno = retornaValor(le, verif);

    if (retorno != NULL) {
        Lista *tmp = *le, *anterior = tmp, *novo = (Lista *) malloc (sizeof(Lista));
        hasMemory(&novo);
        novo->valor = valor;
        novo->prox = retorno;

        while (tmp != retorno) {
            anterior = tmp;
            tmp = tmp->prox;
        }

        if (anterior == tmp) (*le) = novo;
        else anterior->prox = novo;

        textoStatus(6);
    } else textoStatus(8);
}

void removerValorInformado(Lista **le, int valor) {
    Lista *retorno = retornaValor(le, valor);

    if (retorno != NULL) {
        Lista *tmp = *le, *anterior = tmp;
        while (tmp != retorno) {
            anterior = tmp;
            tmp = tmp->prox;
        }
        
        if (anterior == tmp) (*le) = tmp->prox;
        else anterior->prox = tmp->prox;

        free(tmp);

        textoStatus(7);
    } else textoStatus(8);
}

void ordenarListaPorPonteiro(Lista **le) {
    Lista *tmp = *le;
    int contador = 0, tmpValue;

    while (tmp != NULL) {
        tmp = tmp->prox;
        contador++;
    }

    tmp = *le;

    for (int i = 0; i < contador; i++) {
        for (int j = 0; j < contador - i - 1; j++) {
            if (tmp->prox != NULL) {
                if (tmp->valor > (tmp->prox)->valor) {
                    tmpValue = tmp->valor;
                    tmp->valor = tmp->prox->valor;
                    tmp->prox->valor = tmpValue;
                }
            }
            tmp = tmp->prox;
        }
        tmp = *le;
    }

    textoStatus(9);
}

void ordenarListaPorValor(Lista **le) {
    Lista *tmp = *le;
    int contador = 0, a;

    // itens NA lista
    while (tmp != NULL) {
        tmp = tmp->prox;
        contador++;
    }

    int listaValores[contador];
    tmp = *le;

    // itens DA lista
    for (int i = 0; i < contador; i++) {
        listaValores[i] = tmp->valor;
        tmp = tmp->prox;
    }

    // ordenar o vetor
    for (int i = 0; i < contador; i++) {
        for (int j = 0; j < contador - 1 - i; j++) {
            if (listaValores[j] > listaValores[j + 1]) {
                a = listaValores[j + 1];
                listaValores[j + 1] = listaValores[j];
                listaValores[j] = a;
            }
        }
    }

    // jogar os valores ao inves de trabalhar com ponteiros
    tmp = *le;
    for (int i = 0; i < contador; i++) {
        tmp->valor = listaValores[i];
        tmp = tmp->prox;
    }

    textoStatus(9);
}

void adicionarOrdenadoDesdeComeco(Lista **le, int valor) {
    // adiciona os valores ordenadamente, a lista deve iniciar vazia
    Lista *tmp = *le, *anterior = tmp;
    Lista *novo = (Lista *) malloc (sizeof(Lista));
    hasMemory(&novo);

    novo->valor = valor;

    if ((*le) == NULL) {
        (*le) = novo;
        novo->prox = NULL;
    } else {
        if (tmp->valor < valor) {
            while (tmp->valor < valor) {
                if (tmp->prox == NULL) {
                    anterior = tmp;
                    tmp = NULL;
                    break;
                }
                anterior = tmp;
                tmp = tmp->prox;
            }
            anterior->prox = novo;
            novo->prox = tmp;
        } else {
            novo->prox = (*le);
            (*le) = novo;
        }
    }
    textoStatus(6);
}

/*
    <=== MENU ===>
*/
void opcao(Lista **le, int opcao) {
    int valor, valor2;
    Lista *retorno;
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
            cria(le);
            break;
        case 5:
            removeInicio(le);
            break;
        case 6:
            removeFim(le);
            break;
        case 7:
            valor = pegarValor(0);
            retorno = retornaValor(le, valor);
            if (retorno != NULL) printf("Valor: %d\nPonteiro: %p\n", retorno->valor, &(retorno->valor));
            else textoStatus(8);
            break;
        case 8:
            valor = pegarValor(0);
            valor2 = pegarValor(1);
            adicionarNaFrenteDoNo(le, valor, valor2);
            break;
        case 9:
            valor = pegarValor(0);
            valor2 = pegarValor(1);
            adicionarAntesDoNo(le, valor, valor2);
            break;
        case 10:
            valor = pegarValor(0);
            removerValorInformado(le, valor);
            break;
        case 11:
            valor = pegarValor(0);
            adicionarOrdenadoDesdeComeco(le, valor);
            break;
        case 12:
            ordenarListaPorValor(le);
            break;
        case 13:
            ordenarListaPorPonteiro(le);
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
            "8. Adicionar valor apos um segundo numero informado\n"
            "9. Adicionar valor antes de um segundo numero informado\n"
            "10. Remover valor informado\n"
            "11. Criar lista ordenada (deve estar vazia)\n"
            "12. Ordenar uma lista (Fernando)\n"
            "13. Ordenar uma lista (Eu)\n"
            ">> ");
    scanf("%d", &opt);
    system("cls");
    return opt;
}

int main() {
    int opt;
    Lista *le = (Lista *) malloc (sizeof(Lista));
    hasMemory(&le);

    cria(&le);

    do {
        opt = menu();
        opcao(&le, opt);
    } while (opt);

    return 0;
}
