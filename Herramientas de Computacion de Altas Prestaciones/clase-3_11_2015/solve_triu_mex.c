


/* $Revision: 1.1.10.3 $ */

#include "mex.h"

/* The computational routine */
void soltriu(double *A, double *b, mwSize n)
{
    mwSize i,j;
    /* multiply each element y by x */
    for (i=n-1; i>=0; i--) 
          {
           for(j=i+1;j<n; j++)
             {
               b[i]=b[i]-A[i+j*n]*b[j]; 
            }
           b[i]=b[i]/A[i+n*i];
          
            

}
}

/* The gateway function */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[])
{
    double *inMatrix, *invec, *outvec;               /* 1xN input matrix */
    size_t ncols;                   /* size of matrix */
    double *outMatrix;              /* output matrix */
    int i;
    /* check for proper number of arguments */
    if(nrhs!=2) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","One inputs required.");
    }
    if(nlhs!=1) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","One output required.");
    }
    /* make sure the first input argument is scalar */
   
    


    /* create a pointer to the real data in the input matrix  */
    inMatrix = mxGetPr(prhs[0]);
invec = mxGetPr(prhs[1]);

    /* get dimensions of the input matrix */
    ncols = mxGetN(prhs[0]);

    /* create the output matrix */
    plhs[0] = mxCreateDoubleMatrix((mwSize)ncols,1,mxREAL);

    /* get a pointer to the real data in the output matrix */
    outvec = mxGetPr(plhs[0]);
    for (i=0;i<ncols;i++)
      outvec[i]=invec[i];
    /* call the computational routine */
    soltriu(inMatrix,outvec,(mwSize)ncols);
}


