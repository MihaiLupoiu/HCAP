function [ C ] = matrizAxBv1( A, B )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

    M = size(B);
    n= M(1);
    
    C(1:n,1:n)=0; 
    for k = 1:n
        for i = 1:n
           for j = 1:n
                C(i,j) = C(i,j) + A(i,k)*B(k,j);
            end
       end
       
    end

end

