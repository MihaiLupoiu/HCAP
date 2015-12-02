/*=========================================================
 llamada a dgetrs
 *=======================================================*/


#if !defined(_WIN32)
#define dgetrs dgetrs_
#endif

#include "mex.h"
#include "lapack.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double *A,*B;    /* pointer to input matrices */
    double *B2;  /* in/out arguments to DGETRS*/
    size_t m,n,uno=1;     /* matrix dimensions */ 
         char car = 'N';
   mwSignedIndex* iPivot;   /* inputs to DGESV */
    mxArray *Awork, *mxPivot;
    mwSignedIndex info, dims[1];
    int i;
  
 	/* Check for proper number of arguments. */
    if ( nrhs != 3) {
        mexErrMsgIdAndTxt("MATLAB:midgetrs:rhs",
            "This function requires 3 input matrices.");
    }

    A = mxGetPr(prhs[0]); /* pointer to first input matrix */
    B = mxGetPr(prhs[1]); /* pointer to second input matrix */
    
    iPivot=(mwSignedIndex*)mxGetData(prhs[2]);
    /* dimensions of input matrices */
    m = mxGetM(prhs[0]);  
    n = mxGetN(prhs[0]);
    //n = mxGetN(prhs[1]);

    /* Validate input arguments */
//     if (p != mxGetM(prhs[1])) {
//         mexErrMsgIdAndTxt("MATLAB:matrixDivide:matchdims",
//             "Inner dimensions of matrices do not match.");
//     }
    if (n != m) {
        mexErrMsgIdAndTxt("MATLAB:midgetrs:square",
            "LAPACK function requires input matrix 1 must be square.");
    }
//     if (n != 1) {
//         mexErrMsgIdAndTxt("MATLAB:matrixDivide:zerodivide",
//             "For this example input matrix 2 must be a column vector.");  
//     }

    /* DGESV works in-place, so we copy the inputs first. */
//     Awork = mxCreateDoubleMatrix(m, p, mxREAL);
//     A2 = mxGetPr(Awork);
    plhs[0] = mxCreateDoubleMatrix(m, 1, mxREAL);
    B2 = mxGetPr(plhs[0]);
    memcpy(B2, B, m*1*mxGetElementSize(prhs[1]));
  //  memcpy(B2, B, p*n*mxGetElementSize(prhs[1]));
  
    /* Create inputs for DGESV */
 //    dims[0] = m;
//     dims[1] = 1;
//     mxPivot=mxCreateNumericArray(1, dims, mxINT64_CLASS, mxREAL);
//    plhs[1] = mxPivot;
//    iPivot = (int*)mxGetData(plhs[1]);
  //  plhs[1]=mxPivot;
  
    /* Call LAPACK */
    dgetrs(&car,&m,&uno,A,&m,iPivot,B2,&m,&info);
   
    /* plhs[0] now holds X */
  
   // mxDestroyArray(Awork);
   // mxDestroyArray(mxPivot);
}
