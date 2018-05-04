#************************************************************************
#
# Makefile for ASEN 4057 Final Project
# 
# Clean up directory by removing *.o and matMult
# >make clean
#
# ************************************************************************

OPTIMIZATION = -o

matMult: matMult.c getCacheSize.c
	gcc -o matMult matMult.c getCacheSize.c -lm

matMultv2: matMultv2.c getCacheSize.c
	gcc -o matMult2 matMultv2.c getCacheSize.c -lm -lblas
clean: 
	rm -f *.o matMult
	rm -f *.o matMultv2
