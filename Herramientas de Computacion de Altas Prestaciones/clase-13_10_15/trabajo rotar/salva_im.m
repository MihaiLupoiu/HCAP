function salva_im(file,imagenRGB)
nf=size(imagenRGB,1);
nc=size(imagenRGB,2);
fid=fopen(file,'w');
fprintf(fid,'%d %d\n',nf,nc)
for j=1:nf
    for i=1:nf
        fprintf(fid,'%hu\n%hu\n%hu\n',imagenRGB(i,j,1),imagenRGB(i,j,2),imagenRGB(i,j,3));
    end
end    
fclose(fid)