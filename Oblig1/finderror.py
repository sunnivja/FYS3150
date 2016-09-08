#Compute relative error for array u:
from numpy import array, zeros, log, linspace, exp, size




def find_error(filename):
	with open(filename) as infile:
		line = infile.readline()
		lines = line.split()
		n = int(lines[1].replace("=", ""))
		print n
		u = zeros((n, 1))
		infile.readline()
		i = 0
		for line in infile:
			u[i] = float(line)
			i += 1
	x = linspace(0, 1, n+1)
	exact_sol = 1 - (1 - exp(-10))*x - exp(-10*x)
	error = log(abs(u - exact_sol)) - log(abs(exact_sol))
	print error
	print abs(u - exact_sol)/abs(exact_sol)
	return error

find_error("Nmodtest.txt")





