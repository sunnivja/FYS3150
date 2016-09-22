#Program for comparing the eigenvalues found by Jacobi's method and the armadillo function "eigsys"
import numpy as np
import matplotlib.pyplot as mpl



Eigenvalues_Jacobi = ;
Eigenvalues_armadillo = ;
Difference = np.zeros(len(Eigenvalues_Jacobi));


for i in range(len(Eigenvalues_Jacobi)):
	Difference[i] = abs(Eigenvalues_Jacobi[i] - Eigenvalues_armadillo[i]);


plot(Difference)

