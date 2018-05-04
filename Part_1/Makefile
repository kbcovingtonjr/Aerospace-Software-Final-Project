#************************************************************************
#
# Makefile for ASEN 4057 Final Project
# 
# Clean up directory by removing *.o and matMult
# >make clean
#
# Profile with
# >make profile
#
# ************************************************************************

matMult: matMult.c getCacheSize.c
	gcc -o matMult matMult.c getCacheSize.c -lm

profile: matMult.c getCacheSize.c
	gcc -pg -c matMult.c getCacheSize.c
	gcc -pg -o matMult matMult.o getCacheSize.o -lm

matMultv2: matMultv2.c getCacheSize.c
	gcc -o matMult2 matMultv2.c getCacheSize.c -lm -lblas

clean: 
	rm -f *.o matMult
	rm -f *.o matMultv2
