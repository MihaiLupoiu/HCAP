#include "mex.h"

void matprod(double *A, double *B, double *C, mwSize n)
{
	mwSize i,j,k;
	/* multiply each element y by x */
	for(j=0; j<n; j++)
		for(k=0;k<n; k++)
			for(i=0;i<n; i++)
			{
				C[i+j*n]= C[i+j*n]+ A[i+k*n]* B[k+j*n];
			}
}


/* The gateway function */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[])
{
    double *inMatrix1;               /* 1xN input matrix */
    double *inMatrix2;               /* 1xN input matrix */
    size_t ncols;                   /* size of matrix */
    double *outMatrix;              /* output matrix */

    /* check for proper number of arguments */
    if(nrhs!=2) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","Two inputs required.");
    }
    if(nlhs!=1) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","One output required.");
    }
    
    /* get the value of the scalar input  */
    inMatrix1 = mxGetPr(prhs[0]);

    /* create a pointer to the real data in the input matrix  */
    inMatrix2 = mxGetPr(prhs[1]);

    /* get dimensions of the input matrix */
    ncols = mxGetN(prhs[1]);

    /* create the output matrix */
    plhs[0] = mxCreateDoubleMatrix((mwSize)ncols,(mwSize)ncols,mxREAL);

    /* get a pointer to the real data in the output matrix */
    outMatrix = mxGetPr(plhs[0]);

    /* call the computational routine */
    matprod(inMatrix1,inMatrix2,outMatrix,(mwSize)ncols);
}