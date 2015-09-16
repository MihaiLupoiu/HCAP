%For

n = 5

x = []; for i = 1:n, x=[x,i^2],  end

    % o
    
x =[];
for i = 1:n,
    x=[x,i^2],
end

%while

a = 4
n = 0;
while 2^n < a
    n = n + 1;
end
n

%if

if n < 0 
    parity = 0;
elseif rem(n,2) == 0 
    parity = 2;
else
    parity =1;
end
%%
%   <   menor que
%   >   mayor que
%   <=  menor o igual que >= mayor o igual que == igual que
%   ~=  distinto que 

% Para combinar las relaciones: 
%   &   y 
%   |   o
%   ~   no

% (el s�mbolo ~ se puede obtener como Alt -126)


%Este fichero representa la funci�n y=sin(x)-2*cos(x) % en el intervalo [-pi,2*pi]
x=-pi:0.2:2*pi;
n=length(x);

for i=1:n 
    y(i)=sin(x(i))-2*cos(x(i));
end
plot(x,y)

% Suma de vectores por bucle
v=[1,2,3,4]; 
w=[5,6,7,8]; 
for i=1:4
    z(i)=v(i)+w(i);
end
z

%pause %pausa el programa hasta tocar una tecla

% Suma de vectores ?vectorizada?
zv=v+w


% Queremos calcular el volumen de 100000 conos, dados 100000 Diametros y % 100000 alturas: % generamos aleatoriamente Diametros y alturas
numero_conos=100000; 
D=rand(1,numero_conos)+10; 
H=rand(1,numero_conos)+10; 

%versi�n con bucle
tic
for n=1:numero_conos
    V(n) = (1/12)*pi*(D(n)^2)*H(n); 
end
tiempo_bucle=toc

% version vectorizada
tic 
Vv=(1/12)*pi*(D.^2).*H; %Observa los usos del punto antes del operador
tiempo_vectorizado=toc


tic
i = 0;
for t = 0:.01:100
    i = i + 1;
    y(i) = sin(t); 
end

tiempo_bucle=toc

% versi�n vectorizada
tic
t = 0:.01:100;
y = sin(t); 
tiempo_vectorizada=toc

