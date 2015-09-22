//
// Created by Mihaita Alexandru Lupoiu on 22/9/15.
//

// gcc archivo_prueba.c -o normal & gcc archivo_prueba.c -O3 -o optimizado

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void matrizAxBv1(double *A, double* B, double* C, int n){
    int i,j,k = 0;

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            for (k = 0; k < n; ++k) {
                C[i+j*n] = C[i+j*n] + A[i+k*n]*B[k+j*n];
            }
        }
    }
}

void matrizAxBv2(double *A, double* B, double* C, int n){
    int i,j,k = 0;

    for (k = 0; k < n; ++k) {
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                C[i+j*n] = C[i+j*n] + A[i+k*n]*B[k+j*n];
            }
        }
    }
}

void matrizAxBv3(double *A, double* B, double* C, int n){
    int i,j,k = 0;

    for (k = 0; k < n; ++k) {
        for (j = 0; j < n; ++j) {
            for (i = 0; i < n; ++i) {
                C[i+j*n] = C[i+j*n] + A[i+k*n]*B[k+j*n];
            }
        }
    }
}

int main( int argc, char *argv[] ) {

    int m=1000, n=1000,i;
    clock_t tic,toc;


    double *A = (double *) malloc( m*n*sizeof(double) );
    double *B = (double *) malloc( m*n*sizeof(double) );
    double *C = (double *) malloc( m*n*sizeof(double) );
    /* Reservamos memoria para los datos */



    /* Lo probamos */
    int j;
    for( j=0; j<m; j++ ) {
        for( i=0; i<n; i++ ) {
            A[i+j*n] = ((double) rand()/ RAND_MAX);
        }
    }
    for( j=0; j<m; j++ ) {
        for( i=0; i<n; i++ ) {
            B[i+j*n] = ((double) rand()/ RAND_MAX);
        }
    }
    tic = clock();
    //matprod(A, B, C,n);
    matrizAxBv1(A, B, C,n);
    toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    free(C);
    C = (double *) malloc( m*n*sizeof(double) );


    tic = clock();
    //matprod(A, B, C,n);
    matrizAxBv2(A, B, C,n);
    toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);


    free(C);
    C = (double *) malloc( m*n*sizeof(double) );


    tic = clock();
    //matprod(Am, B, C,n);
    matrizAxBv3(A, B, C,n);
    toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);



    /* Liberamos memoria */
    free(A);
    free(B);
    free(C);
    return 0;
}