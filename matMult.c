#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "headers.h"

void rand_matrix(int n, float **arrA, float **arrB);

int main(int argc, char *argv[])
{


	// Get cache size of computer
	int cacheSize = getCacheSize();
        printf("Cache size of this computer's processor: %d Bytes\n", cacheSize);

	// Update progress
	printf("Initializing matrices...\n");
	
	int n = 10000;
	int i,j,k,z;
		
	float **arrA,**arrB,**arrC;
	
	//declare first matrix, A
	arrA = (float**)calloc(n,sizeof(float*));
	
	printf("rows of A defined\n");
	arrA[0] = (float*)calloc(n^2,sizeof(float));
	
	for(i = 1;i < n;i++)
	{
		arrA[i] = arrA[i-1] + n;
	}
	printf("A done\n");

	//read in second matrix
	arrB = (float**)calloc(n,sizeof(float*));
	arrB[0] = (float*)calloc(n^2,sizeof(float));
	printf("B initial declaration\n");
	for(i = 1;i < n;i++)
	{
		arrB[i] = arrB[i-1] + n;
	}
	printf("B done\n");
	arrC = (float**)calloc(n,sizeof(float*));
	arrC[0] = (float*)calloc(n^2,sizeof(float));
	printf("C initial declaration");

	for(i = 1;i < n;i++)
	{
		printf("%d\n",i);
		arrC[i] = arrC[i-1] + n;
	}
	for(j = 0;j < n;j++)
	{
		for(k = 0;k < n;k++)
		{
			arrC[j][k] = 0;
		}
	}

	printf("matrices allocated\n");
	/*
	// Create random matrices
	rand_matrix(n, arrA, arrB);
	
	// Iterators
	int  ii, kk;

	// Update progress
	printf("Computing matrix product(unoptimized)...\n");
	
	// Begin clock
	clock_t begin, end;
	double time_spent;
	begin = clock();

	// Compute matrix product

	int acc00, acc01, acc10, acc11;
	int ib = 2;
	int kb = 2;
	
	for (ii = 0; ii < n; ii += ib)
	{
		for (kk = 0; kk < n; kk += kb)
		{
			for (j = 0; j < n; j += 2)
			{
				for (i = ii; i < ii + ib; i += 2)
				{
					if (kk == 0)
						acc00 = acc01 = acc10 = acc11 = 0;
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
	printf("Time spent computing matrix product(unoptimized): %lf\n",time_spent);
	
	printf("Matrix Product: \n");
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			printf("%f ",arrC[i][j]);
		}
		printf("\n");
	}		

	printf("--------------------------------------------------");

	// -----------------------------------------------------------------
	
	float blockDim = sqrt( cacheSize / sizeof(float) );
	printf("%f\n", blockDim);
	
	// Update progress
	printf("Computing matrix product(optimized)...\n");
	
	// Begin clock
	begin = clock();

	// Compute matrix product
	ib = z;
	kb = z;

	for (ii = 0; ii < n; ii += ib)
	{
		for (kk = 0; kk < n; kk += kb)
		{
			for (j = 0; j < n; j += 2)
			{
				for (i = ii; i < ii + ib; i += 2)
				{
					if (kk == 0)
						acc00 = acc01 = acc10 = acc11 = 0;
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
	printf("Time spent computing matrix product(optimized): %lf\n",time_spent);
	
	printf("Matrix Product(optimized): \n");
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			printf("%f ",arrC[i][j]);
		}
		printf("\n");
	}		

	// -----------------------------------------------------------------





	*/
	free(arrA);
	free(arrB);
	free(arrC);
	
	
	return 0;
	
}

void rand_matrix(int n, float **arrA, float **arrB)
{
	int i, j;
	srand ( time(NULL) );
	
	for (i = 0; i < n; i++)
	{		
		for (j = 0; j < n; j++)
		{
			printf("HERE");
			arrA[i][j] = (float) rand() / RAND_MAX;
			arrB[i][j] = (float) rand() / RAND_MAX;
		}
	}
}
