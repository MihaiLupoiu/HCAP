function [b ] = solve_triu( A,b )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
[m,n]=size(A);
for  i=n:-1:1
 for j=i+1:n
     b(i)=b(i)-A(i,j)*b(j);
 end
 b(i)=b(i)/A(i,i);
end

