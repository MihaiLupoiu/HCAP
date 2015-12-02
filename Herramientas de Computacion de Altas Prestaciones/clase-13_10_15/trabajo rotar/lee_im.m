function imagenRGB=lee_im(file)

fid=fopen(file,'r');
nf=fscanf(fid,'%d',1);
nc=fscanf(fid,'%d',1);
M=uint8(fscanf(fid,'%hu',nf*nc*3));
%imagenRGB=zeros(nf,nc,3);
red=reshape(M(1:3:end),nf,nc);
green=reshape(M(2:3:end),nf,nc);
blue=reshape(M(3:3:end),nf,nc);
imagenRGB(1:nf,1:nf,1)=red;
imagenRGB(1:nf,1:nf,2)=green;
imagenRGB(1:nf,1:nf,3)=blue;
fclose(fid)