function comprobar( filename )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
[ im ] = lee_im( filename );
[X1,map] = rgb2ind(im,128);
figure, image(X1), colormap(map);
end

