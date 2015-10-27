/*=========================================================
 * matrixDivide64.c - Example for illustrating how to use 
 * LAPACK within a C MEX-file. MOdificado para SO de 64 bits
 *
 * X = matrixDivide(A,B) computes the solution to a 
 * system of linear equations A * X = B
 * using LAPACK routine DGESV, where 
 * A is an N-by-N matrix  
 * X and B are N-by-1 matrices.
 *
 * This is a MEX-file for MATLAB.
 * Copyright 2009-2010 The MathWorks, Inc.
 *=======================================================*/
/* $Revision: 1.1.6.3 $ $Date: 2011/01/28 18:11:56 $ */

#if !defined(_WIN32)
#define dgetrs dgetrs_
#endif

#include "mex.h"
#include "lapack.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double *A, *B;    /* pointers to input matrices */
    double *B2;  /* in/out arguments to DGESV*/
    size_t m,n;     /* matrix dimensions */ 
    mwSignedIndex *iPivot;   /* inputs to DGESV */
    mwSignedIndex info;
    size_t uno;
    char *car;

    uno = 1; car = 'N';
    /* Check for proper number of arguments. */
    if ( nrhs != 3) {
        mexErrMsgIdAndTxt("MATLAB:matrixDivide64:rhs",
            "This function requires 3 input matrices.");
    }

    A = mxGetPr(prhs[0]); /* pointer to first input matrix */
    B = mxGetPr(prhs[1]); /* pointer to second input matrix */
    iPivot = (mwSignedIndex*)mxGetData(prhs[2]);
    /* dimensions of input matrices */
    m = mxGetM(prhs[0]);  
    n = mxGetN(prhs[0]);

    /* Validate input arguments */
    if (n != m) {
        mexErrMsgIdAndTxt("MATLAB:matrixDivide64:square",
            "LAPACK function requires input matrix 1 must be square.");
    }

    plhs[0] = mxCreateDoubleMatrix(m, 1, mxREAL);
    B2 = mxGetPr(plhs[0]);
    memcpy(B2, B, m*mxGetElementSize(prhs[1]));
  
    /* Call LAPACK */

    dgetrs(&car, &n, &uno, A, &m, iPivot, B2, &m, &info);

    /* plhs[0] now holds X */
}