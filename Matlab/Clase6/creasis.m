function A=creasis(n, mu);
A=zeros(n*n,n*n);
vd=ones(n*n,1)*(1+4*mu);
A=A+diag(vd);
vdi=-ones(n*n-1,1)*mu;
for i=1:n:n*n-1
    vdi(i)=0;
end
A=A+diag(vdi,1)+diag(vdi,-1);
vdd=-ones(n*n-n,1)*mu;
A=A+diag(vdd,-n)+diag(vdd,n);