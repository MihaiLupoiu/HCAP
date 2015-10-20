#include <stdio.h>
#include <stdlib.h>

void lu2(double *A, int n) {
    int i, j, k;
    /* multiply each element y by x */
    for (k = 0; k < n-1; k++){

        for (i = k+1 ; i < n; i++) {

            A[i+k*n] = A[i+k*n]/A[k+k*n];
        }

        for (j=k+1 ; j < n; j++) {
            for (i=k+1 ; i < n; i++) {
                A[i+j*n]= A[i+j*n]-(A[k+j*n]*A[i+k*n]);
            }
        }
    }
}

/*
 *  2.0000    1.0000    0.5000
    2.0000    3.0000    0.3333
    1.0000    1.0000    1.1667
 */


/* The gateway function */
int main( int argc, char *argv[] ) {
    int n = 3;
    double valor[9] = {2,2,1,2,5,2,1,2,2};

    double* A;
    A = (double *)malloc(sizeof(double)*n*n);
    int i,j;
    for (i = 0; i <n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i*n+j] = valor[i*n+j];
        }
    }
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j)
            printf("%f,",A[i*n+j]);
        printf("\n");
    }
    printf("\n");
    lu2(A,n);

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j)
            printf("%f,",A[i*n+j]);
        printf("\n");
    }

}