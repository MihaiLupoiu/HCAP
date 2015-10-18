#define LIM 32
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#include <pmmintrin.h>

float randfloat()
{
    float r= (float)(rand());
    float div =(float)(1-RAND_MAX);
    return r/div;
}


int main(){
  
float y[LIM],x[LIM],yc[LIM],a;
int i,j;
a=2.0;

for (i=0;i<LIM;i++)
{
  x[i]=-randfloat();
  y[i]=-randfloat();
  yc[i]=y[i];
}


for (i=0;i<LIM;i++)
  {//printf("%f ",x[i]);
   printf("%f ",y[i]);
  }
  printf("\n");

//saxpy
for (i=0;i<LIM;i++)
 y[i]=a*x[i]+y[i];
  


for (i=0;i<LIM;i++)
  {//printf("%f ",x[i]);
   printf("%f ",y[i]);
  }
printf("\n");
 
for (i=0;i<LIM;i++)
  y[i]=yc[i];

//Poner aqui version de saxpy con SSE
__m128 aVector = _mm_set1_ps(a);
__m128 vectorX, vectorY;

for (i=0;i<LIM;i+=4){
    vectorX = _mm_loadu_ps(x+i);
    vectorY = _mm_loadu_ps(y+i);

    vectorX = _mm_mul_ps(vectorX,aVector);
    vectorY = _mm_add_ps(vectorX,vectorY);

    _mm_store_ps(y+i,vectorY);
}

/* con puntero:

__m128 m1;
__m128 ma = _mmset_ps1(a);
  __m128 pSrc1 = (__m128*) x;
  __m128 pSrc2 = (__m128*) y;

for (i=0;i<LIM;i+=4){
  m1 = _mm_mul_ps(*pSrc1, ma);
  *pSrc2 = _mm_add_ps(m1,*pSrc2);
  pSrc1++;
  pSrc2++;
}



*/

for (i=0;i<LIM;i++)
  {//printf("%f ",x[i]);
   printf("%f ",y[i]);
  }
printf("\n");
}
