//
// Created by mihai on 18/10/15.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#include <pmmintrin.h>

typedef unsigned char UINT8;
typedef double FLOAT;
#define K 4.0


FLOAT PSF[12] = {-K/8.0, -K/8.0, -K/8.0, 0, -K/8.0, K+1.0, -K/8.0, 0, -K/8.0, -K/8.0, -K/8.0, 0};

UINT8 matriz[36];

UINT8 res1[36];
UINT8 res2[36];

int main(int argc, char *argv[]){

    int i,j;
    FLOAT temp;

    printf("PSF: ");
    for(i=0; i<12; i++) {
        printf("%f, ",(float)PSF[i]);
    }
    printf("\n");

    for(i=0; i<6; i++) {
        for (j = 0; j < 6; j++) {
            matriz[(i*6)+j] = j;
            printf("%d, ",(int)matriz[(i*6)+j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i=1; i<6; i++) {
        // Skip first and last column, no neighbors to convolve with
        for (j = 1; j < 6; j++) {

            temp=0;
            temp += (PSF[0] * (FLOAT)matriz[((i-1)*6)+j-1]);
            temp += (PSF[1] * (FLOAT)matriz[((i-1)*6)+j]);
            temp += (PSF[2] * (FLOAT)matriz[((i-1)*6)+j+1]);
            temp += (PSF[4] * (FLOAT)matriz[((i)*6)+j-1]);
            temp += (PSF[5] * (FLOAT)matriz[((i)*6)+j]);
            temp += (PSF[6] * (FLOAT)matriz[((i)*6)+j+1]);
            temp += (PSF[8] * (FLOAT)matriz[((i+1)*6)+j-1]);
            temp += (PSF[9] * (FLOAT)matriz[((i+1)*6)+j]);
            temp += (PSF[10] * (FLOAT)matriz[((i+1)*6)+j+1]);

            if(temp<0.0) temp=0.0;
            if(temp>255.0) temp=255.0;
            res1[(i*6)+j]=(UINT8)temp;
        }
    }

    for(i=0; i<6; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d, ",(int)res1[(i*6)+j]);
        }
        printf("\n");
    }
    printf("\n");


    __m128 vectorR,vectorPSF, tmpMul, tmpSum;

    for(i=1; i<6; i++) {
        // Skip first and last column, no neighbors to convolve with
        for (j = 1; j < 6; j++) {

            tmpSum = _mm_setzero_ps();
            vectorPSF = _mm_loadu_ps((float *) PSF + 0);
            printf("PFS: %f %f %f %f\n", vectorPSF[0], vectorPSF[1], vectorPSF[2], vectorPSF[3]);

            vectorR = _mm_cvtpu8_ps(*((__m64 *) matriz + ((i - 1) * 6) + j - 1));
            printf("vectorR: %f %f %f %f\n", vectorR[0], vectorR[1], vectorR[2], vectorR[3]);

            tmpMul = _mm_mul_ps(vectorPSF, vectorR);
            printf("tmpMul: %f %f %f %f\n", tmpMul[0], tmpMul[1], tmpMul[2], tmpMul[3]);

            tmpSum = _mm_add_ps(tmpMul, tmpSum);
            printf("tmpSum: %f %f %f %f\n", tmpSum[0], tmpSum[1], tmpSum[2], tmpSum[3]);

            vectorPSF = _mm_loadu_ps((float *) PSF + 4);
            vectorR = _mm_cvtpu8_ps(*((__m64 *) matriz + ((i) * 6) + j - 1));

            tmpMul = _mm_mul_ps(vectorPSF, vectorR);
            tmpSum = _mm_add_ps(tmpMul, tmpSum);

            vectorPSF = _mm_loadu_ps((float *) PSF + 8);
            vectorR = _mm_cvtpu8_ps(*((__m64 *) matriz + ((i + 1) * 6) + j - 1));

            tmpMul = _mm_mul_ps(vectorPSF, vectorR);
            tmpSum = _mm_add_ps(tmpMul, tmpSum);

            tmpSum = _mm_hadd_ps(tmpSum, tmpSum);
            tmpSum = _mm_hadd_ps(tmpSum, tmpSum);
            _mm_store_ss((float *) &temp, tmpSum);

            if (temp < 0.0) temp = 0.0;
            if (temp > 255.0) temp = 255.0;
            res2[(i * 6) + j] = (UINT8) temp;

            printf("\n");

        }
        printf("\n");
    }

    for(i=0; i<6; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d, ",(int)res2[(i*6)+j]);
        }
        printf("\n");
    }
    printf("\n");

}
