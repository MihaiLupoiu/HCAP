A = magic(1000);
B = magic(1000);

tic
bueno = A*B;
toc

tic
C = matrizAxBv1(A,B);
toc

tic
C1 = matrizAxBv2(A,B);
toc

tic
C = matrizAxBv3(A,B);
toc