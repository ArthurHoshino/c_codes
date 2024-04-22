#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int matrix[5][3], transposta[3][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = rand() % 51;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            printf("[%2.d] ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            transposta[j][i] = matrix[i][j];
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("[%2.d] ", transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}
