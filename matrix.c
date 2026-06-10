#include <stdio.h>
#define SIZE 10

// Function Declarations
void inputMatrix(int mat[SIZE][SIZE], int r, int c);
void displayMatrix(int mat[SIZE][SIZE], int r, int c);
void addMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE], int r, int c);
void multiplyMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE], int r, int c);
void transposeMatrix(int A[SIZE][SIZE], int T[SIZE][SIZE], int r, int c);

int main() {
    int r, c, choice;
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of Matrix A:\n");
    inputMatrix(A, r, c);

    printf("Enter elements of Matrix B:\n");
    inputMatrix(B, r, c);

    printf("\nChoose Operation:\n");
    printf("1. Addition\n2. Multiplication\n3. Transpose of Matrix A\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addMatrix(A, B, C, r, c);
            printf("Result (Addition):\n");
            displayMatrix(C, r, c);
            break;

        case 2:
            multiplyMatrix(A, B, C, r, c);
            printf("Result (Multiplication):\n");
            displayMatrix(C, r, c);
            break;

        case 3: {
            int T[SIZE][SIZE];
            transposeMatrix(A, T, r, c);
            printf("Transpose of Matrix A:\n");
            displayMatrix(T, c, r);
            break;
        }

        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}

// Function Definitions
void inputMatrix(int mat[SIZE][SIZE], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
}

void displayMatrix(int mat[SIZE][SIZE], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void addMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void multiplyMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int A[SIZE][SIZE], int T[SIZE][SIZE], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            T[j][i] = A[i][j];   // row ↔ column swap
}
