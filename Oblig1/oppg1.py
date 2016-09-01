#oblig 1 i python

#1b)
from numpy import *
from scitools.std import plot
aa = -2
bb = 1
cc = 1
x0 = 0
xend = 1
u0 = 0
uend = 0


for N in [10, 100, 1000]:
	f = -100*exp(-10*linspace(x0, xend, N+1))
	f_ = zeros(N+1)
	a = zeros(N+1) + aa
	b = zeros(N) + bb
	c = zeros(N) + cc
	u = zeros(N+1)
	u[0] = u0
	u[-1] = uend


	#Forward substitution:
	for i in range(1, N+1):
		factor = c[i-1]/a[i-1]
		a[i] = a[i] - b[i-1]*factor
		f_[i] = f[i] - f[i-1]*factor

	#Backward substitution:

	for j in range(N+1, 1):
		if j == N:
			u[j] = f_[j]/a[j]
		else:
			u[j] = (f_[j] - b[j]*u[j+1])/a[j]
	plot()







