%Program to read files from the program in 1)
%Project 1, FYS3150
x = linspace(0, 1, length(n1));
plot(x, flip(n1)
%plot(x, -n1, 'bo')
hold 'on'
u = 1 - (1 - exp(-10)).*x - exp(-10.*x);
plot(x, u, 'r')


