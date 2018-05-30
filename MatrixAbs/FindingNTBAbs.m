A = load('QAbs.txt')
I = eye(64,64)
Y = inv(I-A);
fid=fopen('NAbs.txt','wt');
for i=1:size(Y,1)
    fprintf(fid, '%f ', Y(i,:));
    fprintf(fid, '\n\n');
end
fclose(fid);

T = sum(Y,2)
fid=fopen('TAbs.txt','wt');
for i=1:size(T,1)
    fprintf(fid, '%f ', T(i,:));
    fprintf(fid, '\n');
end
fclose(fid);


R = load('RAbs.txt')
B = Y*R
fid=fopen('BAbs.txt','wt');
for i=1:size(B,1)
    fprintf(fid, '%f ', B(i,:));
    fprintf(fid, '\n\n');
end
fclose(fid);