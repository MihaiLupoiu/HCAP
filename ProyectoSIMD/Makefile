CC1=gcc

all:
	$(CC1) -o original.out sharpenOriginal.c -O3
	$(CC1) -o sse_v1.out sharpen2.c -O3
	$(CC1) -o sse_v2.out sharpen3.c -O3

clean:
	rm *.out

