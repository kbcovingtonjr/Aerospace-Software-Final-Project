# Aerospace Software Final Project: Part I

In this part, we optimized the serial performance of the matrix-matrix multiplication given in class by adjusting the size of sub-matrix blocks based on the size of the CPU's cache.

How to Compile/Run: 
------
To run the entire Part II code, which runs the code multiple times using 1, 2 4, and 8:
**> make**
**> matMult 1**  (for un-optimized case)
**> matMult 2**  (for optimized case)

To run and profile:

**> ./Profile.sh 1**  (for un-optimized case)

**> ./Profile.sh 2**  (for optimized case)
