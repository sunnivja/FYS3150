import subprocess

def run_cmd(cmd):
	print " >>", cmd
	subprocess.call(cmd, shell=True)

fname = "solveschrodinger"
header1 = "jacobi"
filename = "elektron1.txt"
plotprogram = "ploteigenvectors.py"
#number of electrons: if 1
noelec1 = 0
#if 2
noelec2 = 1

print "One electron"

run_cmd("g++ -o %s.out %s.cpp %s.cpp" %(fname, fname, header1))

run_cmd("./%s.out %s %s" %(fname, filename, noelec1))

run_cmd("python %s %s" %(plotprogram, filename))

