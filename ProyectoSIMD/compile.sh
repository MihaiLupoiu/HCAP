
#!/bin/sh

make all

echo "===> Original:"
./original.out sunset.ppm

echo "===> SSE V1:"
./sse_v1.out sunset.ppm

echo "===> SSE V2:"
./sse_v2.out sunset.ppm

make clean
