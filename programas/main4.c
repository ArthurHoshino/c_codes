// Diagonais e quadrantes de uma matriz
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    int matrix[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = rand() % 51;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("[%.2d]", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Diagonal principal
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) {
                printf("[%.2d]", matrix[i][j]);
            } else {
                printf("[  ]");
            }
        }
        printf("\n");
    }

    printf("\n");

    // Diagonal secundaria
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i + j == 4) {
                printf("[%.2d]", matrix[i][j]);
            } else {
                printf("[  ]");
            }
        }
        printf("\n");
    }

    printf("\n");

    // Canto superior esquerdo
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i + j) < 4) {
                printf("[%.2d]", matrix[i][j]);
            } else printf("[  ]");
        }
        printf("\n");
    }

    printf("\n");
    // Canto superior direito
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i < j) {
                printf("[%.2d]", matrix[i][j]);
            } else printf("[  ]");
        }
        printf("\n");
    }

    printf("\n");

    // Canto inferior direito
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i + j) > 4) {
                printf("[%.2d]", matrix[i][j]);
            } else printf("[  ]");
        }
        printf("\n");
    }

    printf("\n");
    
    // Canto inferior esquerdo
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i > j) {
                printf("[%.2d]", matrix[i][j]);
            } else printf("[  ]");
        }
        printf("\n");
    }
    
    return 0;
}