/*
    ALOCACAO DINAMICA DE MEMORIA

    Calculo de media de idades
*/

#include <stdio.h>
#include <stdlib.h>

int *p, i;

void leitura (int q) {
	puts("Digite as idades...");
	for (i = 0; i < q; i++) {
		scanf("%d", (p + i));
	}
}

float media(int q) {
	int s = 0;
	
	for (i = 0; i < q; i++) {
		s += *(p + i);
	}
	
	return s/q;
}

int main() {
	int n;
	float m;
	
	system("cls");
	puts("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	
	p = (int *) calloc (n, sizeof(int));
	leitura(n);
	m = media(n);
	printf("Media = %.2f", m);
	
	return 0;
}