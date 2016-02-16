/* 
 * File:   main.c
 * Author: Victor
 *
 * Created on 31 de octubre de 2010, 17:18
 */

#include <stdio.h>
#include <stdlib.h>
#include "rdtsc.h"

typedef struct{
    unsigned short red,green,blue;
} pixel;
void rotate(pixel* p_or, pixel* p_dest,int nf)
{int i,j,veces;
/*for (veces=0;veces<20;veces++)*/
for (i=0;i<nf;i++)
        for (j=0;j<nf;j++)
            p_dest[nf-1-i+nf*j]=p_or[j+nf*i];
}
/*
 * 
 */
int main() {
unsigned long long a,b; 

    FILE* fid;
    fid=fopen("galaxia.txt","r");
    int nf,nc;
    fscanf(fid,"%d %d",&nf,&nc);
    pixel* p;
    pixel* pdest;
    p=(pixel*)malloc(nf*nc*sizeof(pixel));
    pdest=(pixel*)malloc(nf*nc*sizeof(pixel));
    int i,j;
    for (i=0;i<nf*nc;i++)
    {fscanf(fid,"%hu",&p[i].red);
    fscanf(fid,"%hu",&p[i].green);
    fscanf(fid,"%hu",&p[i].blue);
  
    }
    fclose(fid);
    a = rdtsc();  

    rotate(p,pdest,nf);
    b = rdtsc(); printf(" %llu \n  ", b-a); 


    fid=fopen("galaxiar.txt","w");
    fprintf(fid,"%d %d\n",nf,nc);
    for (i=0;i<nf*nc;i++)
    {fprintf(fid,"%hu\n",pdest[i].red);
    fprintf(fid,"%hu\n",pdest[i].green);
    fprintf(fid,"%hu\n",pdest[i].blue);}
    fclose(fid);
    return (EXIT_SUCCESS);
}

