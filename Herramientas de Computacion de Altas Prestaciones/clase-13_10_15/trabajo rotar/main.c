/* 
 * File:   main.c
 * Author: Victor
 *
 * Created on 31 de octubre de 2010, 17:18
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct{
    unsigned short red,green,blue;
} pixel;
/*
 * 
 */
int main() {
    FILE* fid;
/* Leer imagen de archivo galaxia.txt */
    fid=fopen("galaxia.txt","r");
    int nf,nc;
    fscanf(fid,"%d %d",&nf,&nc);
    pixel* p;
    p=(pixel*)malloc(nf*nc*sizeof(pixel));
    int i,j;
    for (i=0;i<nf*nc;i++)
    {fscanf(fid,"%hu",&p[i].red);
     fscanf(fid,"%hu",&p[i].green);
     fscanf(fid,"%hu",&p[i].blue);
    }
/* rotar imagen 90 grados, copiar en pdest */
    pixel* pdest;
    pdest=(pixel*)malloc(nf*nc*sizeof(pixel));
    fclose(fid);
    for (i=0;i<nf;i++)
        for (j=0;j<nf;j++)
            pdest[nf-1-i+nf*j]=p[j+nf*i];
/* Salvar imagen a archivo galaxiar.txt */
    fid=fopen("galaxiar.txt","w");
    fprintf(fid,"%d %d\n",nf,nc);
    for (i=0;i<nf*nc;i++)
    {fprintf(fid,"%hu\n",pdest[i].red);
     fprintf(fid,"%hu\n",pdest[i].green);
     fprintf(fid,"%hu\n",pdest[i].blue);
    }
    fclose(fid);
    return (EXIT_SUCCESS);
}

