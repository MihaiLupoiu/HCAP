/*
 midgetrf
 */

#if !defined(_WIN32)
#define dgetrf dgetrf_
#endif

#include "mex.h"
#include "lapack.h"
// entrada A, salida matriz A2 sobreescrita, ipiv
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double *A;    /* pointer to input matrices */
    double *A2;  /* in/out arguments to DGETRF*/
    size_t m,n;     /* matrix dimensions */ 
   mwSignedIndex* iPivot;   /* inputs to DGESV */
    mxArray  *mxPivot;
    mwSignedIndex info, dims[1];
  
 	/* Check for proper number of arguments. */
    if ( nrhs != 1) {
        mexErrMsgIdAndTxt("MATLAB:midgetrf:rhs",
            "This function requires 1 input matrices.");
    }

    A = mxGetPr(prhs[0]); /* pointer to first input matrix */
    //B = mxGetPr(prhs[1]); /* pointer to second input matrix */
    /* dimensions of input matrices */
    m = mxGetM(prhs[0]);  
    n = mxGetN(prhs[0]);

    if (n != m) {
        mexErrMsgIdAndTxt("MATLAB:midgetrf:square",
            "LAPACK function requires input matrix 1 must be square.");
    }

    plhs[0] = mxCreateDoubleMatrix(m, n, mxREAL);
    A2 = mxGetPr(plhs[0]);
    memcpy(A2, A, m*n*mxGetElementSize(prhs[0]));

     dims[0] = m;
//     dims[1] = 1;
     mxPivot=mxCreateNumericArray(1, dims, mxINT64_CLASS, mxREAL);
    plhs[1] = mxPivot;
    iPivot = (int*)mxGetData(plhs[1]);

  
    /* Call LAPACK */
    dgetrf(&m,&n,A2,&m,iPivot,&info);
   
 
}
