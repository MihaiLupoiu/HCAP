function [b ] = solve_tril_unidad( A,b )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
[m,n]=size(A);
for  i=1:n
 for j=1:i-1
     b(i)=b(i)-A(i,j)*b(j);
 end
 %no es necesario dividir por L(i,j) por que es 1
end

