#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

// Função para imprimir a matriz
void imprimirMatriz(int matriz[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para limpar a matriz
void limparMatriz(int matriz[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matriz[i][j] = 0;
        }
    }
}

// Cone apontando para baixo
void cone(int matriz[SIZE][SIZE]) {
    int centro = SIZE / 2;
    for (int i = 0; i <= centro; i++) {
        for (int j = centro - i; j <= centro + i; j++) {
            matriz[i][j] = 1;
        }
    }
}

// Cruz
void cruz(int matriz[SIZE][SIZE]) {
    int centro = SIZE / 2;
    for (int i = 0; i < SIZE; i++) {
        matriz[i][centro] = 1;  // coluna central
        matriz[centro][i] = 1;  // linha central
    }
}

// Octaedro (losango)
void octaedro(int matriz[SIZE][SIZE]) {
    int centro = SIZE / 2;
    int raio = centro;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (abs(i - centro) + abs(j - centro) <= raio) {
                matriz[i][j] = 1;
            }
        }
    }
}

int main() {
    int matriz[SIZE][SIZE];
    int opcao;

    printf("Escolha a forma:\n");
    printf("1 - Cone\n");
    printf("2 - Cruz\n");
    printf("3 - Octaedro (losango)\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    limparMatriz(matriz);

    switch (opcao) {
        case 1:
            cone(matriz);
            break;
        case 2:
            cruz(matriz);
            break;
        case 3:
            octaedro(matriz);
            break;
        default:
            printf("Opcao invalida!\n");
            return 0;
    }

    printf("\nResultado:\n");
    imprimirMatriz(matriz);

    return 0;
}
