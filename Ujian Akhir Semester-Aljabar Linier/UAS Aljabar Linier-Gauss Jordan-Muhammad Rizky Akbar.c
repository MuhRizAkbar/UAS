#include <stdio.h>
#include <math.h>

#define N 3

void tampilkan_matriks(double matriks[N][N+1]) {
    for (int i = 0; i < N; i++) {
        printf("|");
        for (int j = 0; j < N; j++) {
            printf("%8.0f", matriks[i][j]);
        }
        printf("| ");
        printf("%8.0f", matriks[i][N]);  
        printf(" |\n");
    }
    printf("\n");
}
void gauss_jordan(double A[N][N+1], double solusi[N]) {
    for (int i = 0; i < N; i++) {
        double pivot = A[i][i];
        for (int j = 0; j < N+1; j++) {
            A[i][j] /= pivot;
        }

        printf("\nSetelah membuat pivot di baris %d:\n", i+1);
        tampilkan_matriks(A);

        for (int k = 0; k < N; k++) {
            if (k != i) {
                double factor = A[k][i];
                printf("Baris ke-%d dikurangi %.3f kali baris ke-%d:\n", k+1, factor, i+1);
                for (int j = 0; j < N+1; j++) {
                    A[k][j] -= factor * A[i][j];
                }
                tampilkan_matriks(A);
            }
        }
    }
    printf("\nMatriks Hasil Akhir:\n");
    tampilkan_matriks(A);

    for (int i = 0; i < N; i++) {
        solusi[i] = fabs(A[i][N]);
    }
}
void input_matriks(double A[N][N+1]) {
    printf("Masukkan elemen matriks A (3x3):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Masukkan elemen matriks B (3x1):\n");
    for (int i = 0; i < N; i++) {
        scanf("%lf", &A[i][N]);
    }
}

int main() {
    double A[N][N+1];
    double solusi[N];

    input_matriks(A);

    printf("\nMatriks Awal:\n");
    tampilkan_matriks(A);

    gauss_jordan(A, solusi);

    printf("\nHasil Solusi:\n");
    for (int i = 0; i < N; i++) {
        printf("X%d: %.3f\n", i+1, solusi[i]);
    }

    return 0;
}
