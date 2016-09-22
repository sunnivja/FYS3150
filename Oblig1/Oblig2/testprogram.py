#Testing the program for the Jacobi method

import sys
from numpy import *

Jacobifile = string(sys.argv[1])
Armadillofile = string(sys.argv[2])


with open(Jacobifile) as infile:
	n = length(Jacobifile)
	Jacobi_eigenvalues = zeros(n, 1)
	for i in range(n):
		Jacobi_eigenvalues[i] = double(infile[i])

with open(Armadillofile) as infile:
		n = length(Armadillofile)
	Armadillo_eigenvalues = zeros(n, 1)
	for i in range(n):
		Armadillo_eigenvalues[i] = double(infile[i])




