// Trocar valores de variaveis sem usar referencia
#include <stdio.h>

struct Valor {
    int v1;
    int v2;
};

// struct Valor troca(int a, int b, struct Valor v) {
//     v.v1 = b;
//     v.v2 = a;
//     return v;
// };

struct Valor troca(struct Valor v) {
    int a = v.v1;
    v.v1 = v.v2;
    v.v2 = a;

    return v;
}

int main() {
    struct Valor valores = {5, 10};

    printf("Antes =====> A = %d; B = %d\n", valores.v1, valores.v2);
    valores = troca(valores);
    printf("Depois =====> A = %d; B = %d\n", valores.v1, valores.v2);

    return 0;
}
