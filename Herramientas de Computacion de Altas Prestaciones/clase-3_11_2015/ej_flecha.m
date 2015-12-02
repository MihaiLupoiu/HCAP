function ej_flecha(n)
p1=zeros(n,n);
p1(1,:)=rand(1,n);
p1(:,1)=rand(n,1);
p1=p1+diag(rand(n,1));
spy(p1)
pause
spy(lu(p1))
pause
p1=p1(n:-1:1,n:-1:1);
spy(p1)
pause
spy(lu(p1))