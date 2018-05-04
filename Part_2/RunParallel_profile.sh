#!/bin/bash
# 
# Bash script used to initialize the openMP setup (i.e. # of 
# threads) and run program.
#
# This version of the script also profiles the code.

echo "Compiling, linking, etc..."
make profile
echo ""

echo "Running optimized code with 8 threads..."
export OMP_NUM_THREADS="8"
./matMult_par
gprof matMult_par gmon.out > analysis.txt
echo ""

