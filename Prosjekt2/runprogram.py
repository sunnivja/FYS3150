import subprocess

def run_cmd(cmd):
	print " >>", cmd
	subprocess.call(cmd, shell=True)

fname = "solveschrodinger"
header1 = "jacobi"
header2 = "testprogram"
filename = "elektron1.txt"
plotprogram = "ploteigenvectors.py"
N = 100;
#number of electrons: if 1
noelec1 = 0
#if 2
noelec2 = 1



print "One electron"

run_cmd("g++ -o %s.out %s.cpp %s.cpp %s.cpp" %(fname, fname, header1, header2))

run_cmd("./%s.out %s %s %s" %(fname, filename, noelec2, N))

#run_cmd("python %s %s" %(plotprogram, filename))

