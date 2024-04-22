printf("Placeholder (comeco): %d\n", placeholder->valor);
if (isMenorValor == 1) placeholder->prox = anterior->prox;
else {
    placeholder = anterior;
    placeholder->prox = tmp->prox;
}
printf("Placeholder (depois): %d\n", placeholder->valor);

anterior = tmp->prox;
tmp->prox = (tmp->prox)->prox;

printf("Valor 'anterior' %d --- %p", anterior->valor, anterior->prox);
if (anterior->prox != NULL) {
    printf(" >> %d (ponteiro do prox em relacao a 'anterior')", (anterior->prox)->valor);
}

printf("\nValor prox em relacao ao placeholder: %d", (placeholder->prox)->valor);

printf("Anterior (comeco): %d\n", anterior->valor);
printf("Anterior (final): %d\n", anterior->valor);

printf("Tmp (comeco): %d\n", tmp->valor);
printf("Tmp (final): %d", tmp->valor);
if (tmp->prox != NULL) printf(" -> %d\n", (tmp->prox)->valor);
else printf("\n");

printf("\n\n\nAtual: %d", tmp->valor);
if (tmp->prox != NULL) printf(" --- Proximo: %d\n", (tmp->prox)->valor);
else printf("\n");



if (trocaEntreNumerosDistantes) {
    anterior = tmp->prox;
    tmp->prox = anterior->prox;

    if (primeiro) {
        (*le) = anterior;
    }

    placeholder = anterior;
    placeholder->prox = tmp; // antes era 'anterior'
    anterior->prox = placeholder; // antes era 'tmp'
}
