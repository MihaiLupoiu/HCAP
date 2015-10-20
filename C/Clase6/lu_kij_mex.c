#include "mex.h"

void lu2(double *A, mwSize n) {
    mwSize i, j, k;
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

    /*
    for k=1:n-1
        for i=k+1:n
                A(i,k)=A(i,k)/A(k,k);
        end
        for j=k+1:n
            for i=k+1:n;
                A(i,j)=A(i,j)-A(k,j)*A(i,k);
            end
       end
    end
    */

}


/* The gateway function */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[])
{
    double *inMatrix1;               /* 1xN input matrix */
    size_t ncols;                   /* size of matrix */
    double *outMatrix;              /* output matrix */

    /* create a pointer to the real data in the input matrix  */
    inMatrix1 = mxGetPr(prhs[0]);

    /* get dimensions of the input matrix */
    ncols = mxGetN(prhs[0]);

    /* create the output matrix */
    plhs[0] = mxCreateDoubleMatrix((mwSize)ncols,(mwSize)ncols,mxREAL);

    /* get a pointer to the real data in the output matrix */
    outMatrix = mxGetPr(plhs[0]);

    int i,j;
    for (i = 0; i < ncols; ++i) {
        for (j = 0; j < ncols; ++j)
            outMatrix[i+j*ncols] = inMatrix1[i+j*ncols];
    }

    /* call the computational routine */
    lu2(outMatrix,(mwSize)ncols);

}