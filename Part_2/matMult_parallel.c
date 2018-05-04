#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#include "headers.h"


// Define the size of the nxn matrices we're working with
#define n 2000

// Allocate matrices on heap
float arrA[n][n],arrB[n][n],arrC[n][n];

int main(int argc, char *argv[])
{

	// Print matrix size
        printf("Size of matrix: [%d x %d]\n", n,n);

	// Get cache size of computer
	int cacheSize = getCacheSize();
        printf("Cache size of this computer's processor: %d Bytes\n", cacheSize);
	int nAvail = sqrt(cacheSize/sizeof(float));
	printf("Dimension size of matrix that can fit in cache: [%d x %d] \n", nAvail,nAvail);

	// Set margin
	//int margin = n / 4;	// number of rows/columns to reserve to pad the cache
	int margin = 0;	// number of rows/columns to reserve to pad the cache

	// Figure out a good size for the matrix blocks
	int numBlocks = 1;
	int blockSize = n;
	do {
		blockSize = n / numBlocks;
		numBlocks++;
	}
	while ( blockSize > nAvail-margin );

        printf("Block size chosen: [%d x %d] \n", blockSize, blockSize);
	

	// ---------------------- INITIALIZE MATRICES --------------------
	printf("Initializing matrices...");

	// Create random matrices
        // rand_matrix(n, arrA, arrB);
	for (int i = 0; i < n; i++)           
	{	
		//printf("Row = %d\n",i); 	
		for (int j = 0; j < n; j++)                         
		{         
        		arrA[i][j] = (float) rand() / RAND_MAX;
        		arrB[i][j] = (float) rand() / RAND_MAX;
			arrC[i][j] = 0.0;
			//printf("A[%d][%d] = %lf\n",i,j,arrA[i][j]);
		}
	}
	printf(" initialized\n\n");
	// ---------------------------------------------------------------

	/*
	// ----------------- COMPUTE PRODUCT (UNOPTIMIZED) ---------------
	// Update progress
	printf("--------------------------------------------------\n");
	printf("Computing matrix product (unoptimized)...\n");
	
	//int ii, kk;
	
	// Begin clock
	clock_t begin, end;
	double time_spent;
	begin = clock();

	// Compute matrix product

	float  acc00, acc01, acc10, acc11;
	int ib = 2;
	int kb = 2;
	
	for (int ii = 0; ii < n; ii += ib)
	{
		for (int kk = 0; kk < n; kk += kb)
		{
			for (int j = 0; j < n; j += 2)
			{
				for (int i = ii; i < ii + ib; i += 2)
				{
					if (kk == 0)
						acc00 = acc01 = acc10 = acc11 = 0.0;
					else
					{
						acc00 = arrC[i][j];
						acc01 = arrC[i][j+1];
						acc10 = arrC[i+1][j];
						acc11 = arrC[i+1][j+1];
					}	
					for (int k = kk; k < kk + kb; k++)
					{
						acc00 += arrA[i][k]*arrB[k][j];
						acc01 += arrA[i][k]*arrB[k][j+1];
						acc10 += arrA[i+1][k]*arrB[k][j];
						acc11 += arrA[i+1][k]*arrB[k][j+1];
					}
					arrC[i][j] = acc00;
					arrC[i][j+1] = acc01;
					arrC[i+1][j] = acc10;
					arrC[i+1][j+1] = acc11;
				}
			}
		}
	}

	// Stop clock
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent computing matrix product(unoptimized): %lf seconds\n",time_spent);

	
	printf("Matrix Product: \n");
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			printf("%f",arrC[i][j]);
		}
		printf("\n");
	}		
	
	printf("--------------------------------------------------\n\n");
	// ---------------------------------------------------------------
	*/


	// ----------------- COMPUTE PRODUCT (OPTIMIZED) -----------------
	// Update progress
	printf("--------------------------------------------------\n");
	printf("Computing matrix product (optimized)...\n");
	
	// Begin clock
	clock_t begin, end;
	double time_spent;
	begin = clock();


	// Set new block size
	int ib = blockSize;
	int kb = blockSize;
	int i,j,k,ii,kk;
	float acc00,acc01,acc10,acc11;


	// Compute matrix product
#pragma omp parallel for private(i,j,k,ii,kk,acc00,acc01,acc10,acc11) shared(arrA,arrB,arrC)     
	for (ii = 0; ii < n; ii += ib)
	{
	int numThreads = omp_get_num_threads();
	printf("Num threads: %d\n", numThreads);

	int numProcs = omp_get_num_procs();
	printf("Num of cores: %d\n", numProcs);

	int ifPar = omp_in_parallel();
	printf("Is parallel: %d\n", ifPar);
		for (kk = 0; kk < n; kk += kb)
		{
			for (j = 0; j < n; j += 2)
			{
				for (i = ii; i < ii + ib; i += 2)
				{
					if (kk == 0)
						acc00 = acc01 = acc10 = acc11 = 0.0;
					else
					{
						acc00 = arrC[i][j];
						acc01 = arrC[i][j+1];
						acc10 = arrC[i+1][j];
						acc11 = arrC[i+1][j+1];
					}	
					for (k = kk; k < kk + kb; k++)
					{
						acc00 += arrA[i][k]*arrB[k][j];
						acc01 += arrA[i][k]*arrB[k][j+1];
						acc10 += arrA[i+1][k]*arrB[k][j];
						acc11 += arrA[i+1][k]*arrB[k][j+1];
					}
					arrC[i][j] = acc00;
					arrC[i][j+1] = acc01;
					arrC[i+1][j] = acc10;
					arrC[i+1][j+1] = acc11;
				}
			}
		}
	}


	// Stop clock
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent computing matrix product (optimized): %lf seconds\n",time_spent);

	/*
	printf("Matrix Product: \n");
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			printf("%f",arrC[i][j]);
		}
		printf("\n");
	}		
	*/
	printf("--------------------------------------------------\n\n");
	// ---------------------------------------------------------------


	//free(arrA);
	//free(arrB);
	//free(arrC);
	
	return 0;
}


/*void rand_matrix(int n, float **arrA, float **arrB)
{
	int i, j;
	srand ( time(NULL) );
	
	for (i = 0; i < n; i++)
	{		
		for (j = 0; j < n; j++)
		{
			arrA[i][j] = (float) rand() / RAND_MAX;
			arrB[i][j] = (float) rand() / RAND_MAX;
		}
		printf("HERE\n");
	}
}*/
