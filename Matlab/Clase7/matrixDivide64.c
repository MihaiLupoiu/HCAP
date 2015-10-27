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
#define dgesv dgesv_
#endif

#include "mex.h"
#include "lapack.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double *A, *B;    /* pointers to input matrices */
    double *A2, *B2;  /* in/out arguments to DGESV*/
    size_t m,n,p;     /* matrix dimensions */ 
    mwSignedIndex *iPivot;   /* inputs to DGESV */
    mxArray *Awork, *mxPivot;
    mwSignedIndex info, dims[1];
  
 	/* Check for proper number of arguments. */
    if ( nrhs != 2) {
        mexErrMsgIdAndTxt("MATLAB:matrixDivide64:rhs",
            "This function requires 2 input matrices.");
    }

    A = mxGetPr(prhs[0]); /* pointer to first input matrix */
    B = mxGetPr(prhs[1]); /* pointer to second input matrix */
    /* dimensions of input matrices */
    m = mxGetM(prhs[0]);  
    n = mxGetN(prhs[0]);
    p = mxGetN(prhs[1]);

    /* Validate input arguments */
    if (n != mxGetM(prhs[1])) {
        mexErrMsgIdAndTxt("MATLAB:matrixDivide64:matchdims",
            "Inner dimensions of matrices do not match.");
    }
    if (n != m) {
        mexErrMsgIdAndTxt("MATLAB:matrixDivide64:square",
            "LAPACK function requires input matrix 1 must be square.");
    }
    if (p != 1) {
        mexErrMsgIdAndTxt("MATLAB:matrixDivide:zerodivide",
            "For this example input matrix 2 must be a column vector.");  
    }

    /* DGESV works in-place, so we copy the inputs first. */
    Awork = mxCreateDoubleMatrix(m, n, mxREAL);
    A2 = mxGetPr(Awork);
    plhs[0] = mxCreateDoubleMatrix(m, 1, mxREAL);
    B2 = mxGetPr(plhs[0]);
    memcpy(A2, A, m*n*mxGetElementSize(prhs[0]));
    memcpy(B2, B, m*mxGetElementSize(prhs[1]));
  
    /* Create inputs for DGESV */
    dims[0] = m;
    mxPivot = mxCreateNumericArray(1, dims, mxINT64_CLASS, mxREAL);
    iPivot = (mwSignedIndex*)mxGetData(mxPivot);
  
    /* Call LAPACK */
    dgesv(&m,&p,A2,&m,iPivot,B2,&m,&info);
    /* plhs[0] now holds X */
  
    mxDestroyArray(Awork);
    mxDestroyArray(mxPivot);
}
