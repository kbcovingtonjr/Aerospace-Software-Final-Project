#!/bin/bash
# 
# Bash script used to initialize the openMP setup (i.e. # of 
# threads) and run program.

echo "Compiling, linking, etc..."
make
echo ""

echo "Running optimized code with 1 threads..."
export OMP_NUM_THREADS="1"
echo ""
./matMult_par
echo ""

echo "Running optimized code with 2 threads..."
export OMP_NUM_THREADS="2"
echo ""
./matMult_par
echo ""

echo "Running optimized code with 4 threads..."
export OMP_NUM_THREADS="4"
echo ""
./matMult_par
echo ""

