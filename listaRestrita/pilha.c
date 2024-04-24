#include <stdio.h>
#include <stdlib.h>
#define tam 10

typedef struct {
	int topo;
	int valor[tam];
} pilha;

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

void exibir(pilha *p) {
    textoStatus(4);
    for (int i = p->topo; i >= 0; i--) {
        printf("[ %d ]\n", p->valor[i]);
    }
}

/*
    <=== FUNCOES ===>
*/
void inicia (pilha *p) {
    textoStatus(2);
    p->topo = -1;
}

int isCheia(pilha *p) { return (p->topo == tam - 1); }

int isVazia(pilha *p) { return (p->topo == -1); }

int push(pilha *p, int val) {
	if (isCheia(p)) {
		return 0;
	}
	
	p->valor[++p->topo] = val;
	return 1;
}

int pop(pilha *p, int *val) {
	if (isVazia(p)) return 0;

	*val = p->valor[p->topo--];
	return 1;
}

double dec_to_bin(int valor) {
    pilha *tmp = (pilha *) malloc (sizeof(pilha));
    double valorRetorno;
    int valorTmp;
    inicia(tmp);

    while (valor >= 1) {
        push(tmp, (valor % 2));
        valor /= 2;
    }

    while (!isVazia(tmp)) {
        pop(tmp, &valorTmp);
        if (valorTmp == 1) {
            for (int j = tmp->topo; j >= 0; j--) valorTmp *= 10;
            valorRetorno += valorTmp;
        }
    }

    return valorRetorno;
}

/*
    <=== MENU ===>
*/
void opcao(pilha *p, int opcao) {
    int valor;
    double valorRetorno;
    switch (opcao) {
        case 0:
            break;
        case 1:
            valor = pegarValor(0);
            if (push(p, valor)) textoStatus(6);
            else textoStatus(11);
            break;
        case 2:
            if (pop(p, &valor)) {
                textoStatus(7);
                printf("Valor removido: %d", valor);
            }
            else textoStatus(11);
            break;
        case 3:
            valor = pegarValor(0);
            valorRetorno = dec_to_bin(valor);
            printf("Valor binario: %.0f", valorRetorno);
            break;
        case 4:
            if (isCheia(p)) printf("Lista esta cheia");
            else printf("Lista nao esta cheia");
            break;
        case 5:
            if (isVazia(p)) printf("Lista esta vazia");
            else printf("Lista nao esta vazia");
            break;
        case 99:
            exibir(p);
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
            "1. Inserir valor na pilha\n"
            "2. Remover valor na pilha\n"
            "3. Transformar valor para binario\n"
            "4. Verficar se a lista esta cheia\n"
            "5. Verificar se a lista esta vazia\n"
            "99. Exibir\n"
            ">> ");
    scanf("%d", &opt);
    system("clear");
    return opt;
}

int main() {
    pilha *p = (pilha *) malloc (sizeof(pilha));
    int opt;
    inicia(p);

    do {
        opt = menu();
        opcao(p, opt);
    } while (opt);

    return 0;
}
