# ************************************************************************
#
# Makefile for ASEN 4057 Final Project Part II
# 
# Clean up directory by removing *.o and matMult
# >make clean
#
# ************************************************************************


matMult_par: matMult_parallel.c getCacheSize.c
	gcc -fopenmp -o matMult_par matMult_parallel.c getCacheSize.c -lm
clean: 
	rm -f *.o matMult_par
