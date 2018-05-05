# Aerospace Software Final Project

This repository contains the code for the Final Project in ASEN 4057. In this project, we optimized the serial performance of matrix-matrix multiplication and then parallelized this using openMP.


# Part I

In this part, we optimized the serial performance of the matrix-matrix multiplication given in class by adjusting the size of sub-matrix blocks based on the size of the CPU's cache.

How to Compile/Run: 
------
To run the entire Part II code, which runs the code multiple times using 1, 2 4, and 8:
**> make**

**> matMult 1**  (for un-optimized case)

**> matMult 2**  (for optimized case)


To run and profile the Part I optimized case:

**> ./Profile.sh 1**  (for un-optimized case)

**> ./Profile.sh 2**  (for optimized case)


# Part II

In this part, we parallelized the serial optimized matrix-matrix multiplication from Part I using openMP.

How to Compile/Run: 
------
To run the entire Part II code, which runs the code multiple times using 1, 2 4, and 8:

**> ./RunParallel.sh**


To run and profile the Part II code using 8 threads:

**> ./RunParallel_profile.sh**


If you desire to run a single case, follow the examples in ./RunParallel.sh
