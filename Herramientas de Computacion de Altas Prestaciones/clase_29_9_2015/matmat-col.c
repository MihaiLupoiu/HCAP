#include <stdio.h>
#include <stdlib.h>
#include "ctimer.h"

void matmat(double *A, double *B, double *C, int n) {
  int i,j,k;

  for (i=0;i<n;i++)
    for (j=0;j<n;j++) 
      C[i*n+j] = 0.0;

  for (i=0;i<n;i++)
    for (k=0;k<n;k++)
      for (j=0;j<n;j++) 
        C[i+j*n]+=A[i+k*n]*B[k+j*n];
}

void print(double *A, int n) {
  int i,j;
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++)
      printf("%5.4f ",A[i+j*n]);
    printf("\n");
  }

}

void randmat(double *A, int n) {
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      A[i+j*n] = rand()/(RAND_MAX+1.0);

}

int main( int argc, char *argv[]) {
  double *A, *B, *C; 
  double elapsed0, ucpu0, scpu0;
  double elapsed1, ucpu1, scpu1;
  int n;

  if (argc==2)
    n = atoi(argv[1]);
  else
    n = 16;

  A = (double *)malloc(sizeof(double)*n*n);
  B = (double *)malloc(sizeof(double)*n*n);
  C = (double *)malloc(sizeof(double)*n*n);

  if (!A || !B || !C) 
    printf("Error reservando memoria\n");
  else {
    randmat(A, n); 
    //print(A, n); 
    //printf("\n");
    randmat(B, n); 
    //print(B, n); 
    //printf("\n");

    ctimer_(&elapsed0, &ucpu0, &scpu0);
    matmat(A, B, C, n);
    ctimer_(&elapsed1, &ucpu1, &scpu1);
    printf("Tiempo: %fs (real) %fs (cpu) %fs (sys)\n", 
                 elapsed1-elapsed0, ucpu1-ucpu0, scpu1-scpu0);

    //print(C, n); 

    free(A);
    free(B);
    free(C);
  }

}
