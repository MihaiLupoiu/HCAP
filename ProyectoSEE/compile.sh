
#!/bin/sh

if [ -z "$1" ]
then
    echo "No argument supplied";
    exit;
fi

if [ "$1" == "all" ]; then

	make all
	
	echo "===> GCC <==="
	
	echo "===> Original:"
	./original_gcc.out sunset.ppm
	
	echo "===> SSE V1:"
	./sse_gcc_v1.out sunset.ppm
	
	echo "===> SSE V2:"
	./sse_gcc_v2.out sunset.ppm
	
	echo "===> ICC <==="
	
	echo "===> Original:"
	./original_icc.out sunset.ppm
	
	echo "===> SSE V1:"
	./sse_icc_v1.out sunset.ppm
	
	echo "===> SSE V2:"
	./sse_icc_v2.out sunset.ppm
      
else
	if [ "$1" == "gcc" ]; then
		make gcc

		echo "===> GCC <==="
	
		echo "===> Original:"
		./original_gcc.out sunset.ppm
		
		echo "===> SSE V1:"
		./sse_gcc_v1.out sunset.ppm
		
		echo "===> SSE V2:"
		./sse_gcc_v2.out sunset.ppm
		
	else
		make icc

		echo "===> ICC <==="
	
		echo "===> Original:"
		./original_icc.out sunset.ppm
		
		echo "===> SSE V1:"
		./sse_icc_v1.out sunset.ppm
		
		echo "===> SSE V2:"
		./sse_icc_v2.out sunset.ppm	
	fi
   
fi

make clean
