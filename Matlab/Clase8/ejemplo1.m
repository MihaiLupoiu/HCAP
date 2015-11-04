disp('producto de matrices banda')
p1=gallery('toeppen',20,1,2,3,4,6);
p2=gallery('toeppen',20,1,2,3,4,6);
spy(p1)
pause
spy(p1*p2)
pause
disp('producto de triangulares')
p1=triu(rand(20,20));
p2=triu(rand(20,20));
spy(p1)
title('matriz triangular')
pause
spy(p1*p2)
title('producto de dos triangulares')
pause
disp('producto de dispersas, una con una fila y otra con una columna')
p1=zeros(20,20);
p1(1,:)=rand(1,20);
spy(p1)
title('primera matriz')
pause
p2=zeros(20,20);
p2(:,1)=rand(20,1);
spy(p2)
title('segunda matriz')
pause
spy(p2*p1)
title('producto de las dos :segunda por primera')
pause
spy(p1*p2)
title('producto de las dos :primera por segunda')
pause
p1=gallery('poisson',20)
spy(p1)
pause
p1=lu(p1);
spy(p1)