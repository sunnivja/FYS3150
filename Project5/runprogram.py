#Run program and plot

import cmd
import sys
import os
import subprocess

def run_cmd(cmd):
	print " >>", cmd
	subprocess.call(cmd, shell=True)

filename = 'test.dat';
nr_agents = 500;
nr_transactions = 1e7;
initial_money = 100;
saving = 0;

run_cmd('g++ -std=c++11 project5.cpp');
run_cmd('./a.out %d %d %d %s %f' %(nr_agents, nr_transactions, initial_money, filename, saving))