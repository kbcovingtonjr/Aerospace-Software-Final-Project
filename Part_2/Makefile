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

profile: matMult_parallel.c getCacheSize.c
	gcc -pg -c -fopenmp matMult_parallel.c getCacheSize.c
	gcc -pg -fopenmp -o matMult_par matMult_parallel.o getCacheSize.o -lm

clean: 
	rm -f *.o matMult_par
