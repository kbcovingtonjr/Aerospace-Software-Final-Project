# ************************************************************************
#
# Makefile for ASEN 4057 Final Project
# 
# Clean up directory by removing *.o and matMult
# >make clean
#
# ************************************************************************

OPTIMIZATION = -O3

matMult: matMult.c getCacheSize.c
	gcc $(OPTIMIZATION) -o matMult matMult.c getCacheSize.c -lm

matMultv2: matMultv2.c getCacheSize.c
	gcc $(OPTIMIZATION) -o matMult2 matMultv2.c getCacheSize.c -lm
clean: 
	rm -f *.o matMult
	rm -f *.o matMultv2
