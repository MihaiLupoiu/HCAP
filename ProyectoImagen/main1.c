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

void rotate(pixel* p_or, pixel* p_dest,int nf){
    int i,j,veces;
    for (veces=0;veces<20;veces++){
        for (i=0;i<nf/2;i++){
            for (j=0;j<nf/2;j++){
        		p_dest[nf-1-i+nf*j]=p_or[j+nf*i];
        	 	p_dest[nf-1-i+nf*(nf-1-j)]=p_or[nf-1-j+nf*i];
        		p_dest[i+nf*(nf-1-j)]=p_or[nf-1-j+nf*(nf-1-i)];
        		p_dest[i+nf*j]=p_or[j+nf*(nf-1-i)];	
	       }
	// if(j*2 < nf-1) { rotar elemento que falta; }
       }
   }
}
/*
 * 
 */
int main(int argc, char *argv[]) {
unsigned long long a,b; 

	char * ficheros[2];
	int unused __attribute__((unused));


    if(argc !=3){
        printf("Enter the file path to proces = ");
        unused = scanf("%s",ficheros[0]);
        printf("Enter the file path result = ");
        unused = scanf("%s",ficheros[1]);
    }
    else{
        ficheros[0]=argv[1];
        ficheros[1]=argv[2];
    }

    FILE* fid;
    fid=fopen(ficheros[0],"r");
    int nf,nc;
    unused = fscanf(fid,"%d %d",&nf,&nc);
    pixel* p;
    pixel* pdest;
    p=(pixel*)malloc(nf*nc*sizeof(pixel));
    pdest=(pixel*)malloc(nf*nc*sizeof(pixel));
    int i,j;
    for (i=0;i<nf*nc;i++){
	    unused = fscanf(fid,"%hu",&p[i].red);
	    unused = fscanf(fid,"%hu",&p[i].green);
	    unused = fscanf(fid,"%hu",&p[i].blue);  
    }
    fclose(fid);
	a = rdtsc();  

    rotate(p,pdest,nf);
	b = rdtsc(); printf(" %llu \n  ", b-a); 


    fid=fopen(ficheros[1],"w");
    fprintf(fid,"%d %d\n",nf,nc);
    for (i=0;i<nf*nc;i++){
	    fprintf(fid,"%hu\n",pdest[i].red);
	    fprintf(fid,"%hu\n",pdest[i].green);
	    fprintf(fid,"%hu\n",pdest[i].blue);
    }
    fclose(fid);
    return (EXIT_SUCCESS);
}

