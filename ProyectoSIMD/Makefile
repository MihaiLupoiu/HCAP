CC1=gcc
CC2=icc

gcc:
	$(CC1) -o original_gcc.out sharpenOriginal.c -O3 
	$(CC1) -o sse_gcc_v1.out sharpen2.c -O3 -msse3
	$(CC1) -o sse_gcc_v2.out sharpen3.c -O3 -msse3

icc:
	$(CC2) -o original_icc.out sharpenOriginal.c -O3 
	$(CC2) -o sse_icc_v1.out sharpen2.c -O3
	$(CC2) -o sse_icc_v2.out sharpen3.c -O3
	
all:
	$(CC1) -o original_gcc.out sharpenOriginal.c -O3 
	$(CC1) -o sse_gcc_v1.out sharpen2.c -O3 -msse3
	$(CC1) -o sse_gcc_v2.out sharpen3.c -O3 -msse3
	
	$(CC2) -o original_icc.out sharpenOriginal.c -O3 
	$(CC2) -o sse_icc_v1.out sharpen2.c -O3
	$(CC2) -o sse_icc_v2.out sharpen3.c -O3
	
clean:
	rm *.out

