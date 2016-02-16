function  membrana_lapack(n)
% esta función visualiza el movimiento de una membrana 
% Condiciones de contorno, inicialización de la solución
xn2=zeros(n+2,n+2);
xn1=zeros(n+2,n+2);
y=zeros(n+2,n+2);
 % Diferencial o Incremento de tiempo y su cuadrado
inct=0.05;
inct2=inct*inct;
% Diferencial o Incremento de "espacio" y su cuadrado
incx=1/(n+1);
incx2=incx*incx;
mu=inct2/incx2;
% Valor inicial de la solución.  
% Aquí es interesante cambiar uno (o los dos) de los senos por un coseno,   
% o incrementar la constante KA para que las vibraciones tengan mas amplitud  
KA = 0.01;
for i=2:n+1
   for j=2:n+1
      xn1(i,j)=KA*(sin(pi*i/(n+2))+sin(pi*j/(n+2)));
   end  
end

% En creasis se genera una matriz A de forma que sea todo ceros, salvo:
% 1-- los elementos de la diagonal principal valgan 1+4*mu
% 2-- las diagonales -n, n de A valgan -mu
% 3--- las diagonales 1 y -1 de A valgan -mu, salvo en los siguientes puntos donde valen 0;
%      ==>la diagonal de abajo (-1) vale 0 en las filas 1, n+1, 2*n+1,...,(n-1)*n+1
%      ==>la diagonal de arriba (+1) vale 0 en las filas n, 2*n,...,(n-1)*n

  A = creasis(n,mu);
% aqui vemos la estructura ...
spy(A)
pause
% Creación del objeto película
 M=moviein(25);
% 100 pasos, de "inct" segundos cada uno.
%
t=0;   
%
% tic, [lu,ind]=dgetrf_mex(A); t=t+toc; % resolución con los mex del ejercicio
% 
for tp=1:100
   % cada cuatro pasos, se genera el gráfico de la membrana 
   % y se guarda para la película (un "fotograma").
    if (rem(tp,4)==0)
       surf(y),axis([0 n+2 0 n+2 -0.08 0.08]);
       M(:,tp/4)=getframe;
    end
   % Preparación de la solución 2D en un vector de filas consecutivas
    zn1=reshape(xn1(2:n+1,2:n+1),(n)^2,1);
    zn2=reshape(xn2(2:n+1,2:n+1),(n)^2,1);
    % Resolver el sistema de ecuaciones
    b = 2*zn1-zn2;      
%   RESOLVER EL SISTEMA A*y1=b;
 tic

  y1=matrixDivide64(A,b);
% y1=dgetrs_mex(lu,b,ind);% resolución con los mex del ejercicio
%  
% %resolución con los archivos .m de la práctica anterior
%    lu=lu_kji(A);
%     yaux=solve_tril_unidad(lu,b);
%     y1=solve_triu(lu,yaux);
%     y1=A\b;
 t=t+toc;  
   % Reconstruimos la solución en 2D para visualizar
   y(2:n+1,2:n+1)=reshape(y1,n,n);
   % Avanzamos el paso de tiempo
    xn2=xn1;
    xn1=y;
 end
% Visualizamos la película generada
movie(M);
t