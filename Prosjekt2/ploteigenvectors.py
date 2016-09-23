#This program plots the eigenvectors

from numpy import *
import sys

filename = sys.argv[1]

def plot(filename):
	with open(filename) as infile:
		lines = infile.split()
		n = int(lines[0])
		R = zeros(n, n)
		for i in range(n):
			lines = infile.split()
			for j in range(length(lines)):
				R[i, j] = float(lines[j])
	#plot(R[1, :])

plot(filename)