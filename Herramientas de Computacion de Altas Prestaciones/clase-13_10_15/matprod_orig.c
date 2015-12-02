

/*==========================================================
 * arrayProduct.c - example in MATLAB External Interfaces
 *
 * Multiplies an input scalar (multiplier) 
 * times a 1xN matrix (inMatrix)
 * and outputs a 1xN matrix (outMatrix)
 *
 * The calling syntax is:
 *
 *		outMatrix = arrayProduct(multiplier, inMatrix)
 *
 * This is a MEX-file for MATLAB.
 * Copyright 2007-2010 The MathWorks, Inc.
 *
 *========================================================*/
/* $Revision: 1.1.10.3 $ */

#include "mex.h"

/* The computational routine */
void matprod(double *A, double *B, double *C, mwSize n)
{
    mwSize i,j,k;
    /* multiply each element y by x */
    for (k=0; k<n; k++) 
         for(j=0;j<n; j++)
             for(i=0;i<n; i++)
       {
        C[i*n+j]= C[i*n+j]+ A[i*n+k]* B[k*n+j];
    }
}

