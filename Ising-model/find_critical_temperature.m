%Program for finding the correlation between critical temperature and
%length, based on our estimations if the critical temperature.

T_c = [2.29, 2.29, 2.27, 2.27];
L = [40, 60, 100, 140];
T_c_analytical = 2.269;

%Finding the mean of a:
a = 0;
for i=linspace(1, 3, 3)
        a = a + (T_c(i) + T_c(i+1))/(L(i) - L(i+1));   
end
a = a/3

T_c_limit = mean(-a.*L.^(-1)+ T_c)
error = T_c_analytical - T_c_limit