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
	int memAvail = sqrt(cacheSize/sizeof(double));
	printf("total available memory for matrices: %d\n",memAvail);

	// Update progress
	printf("Initializing matrices...\n");
	
	//*************N CANNNOT BE GREATER THAN 600 OR SEGMENTATION FAULT**************
	int n = 10;
	int i,j,k,z;
	if (3*(n2) > cunkSize)
	{
		printf("ERROR: Not enough memory!");
		return 0;
	}
	else{}
		
	//double **arrA,**arrB,**arrC;
	double arrA[n][n],arrB[n][n],arrC[n][n];

	//////////////////////////////////////////////////////////////////////
	/*
	//declare first matrix, A
	arrA = (double**)calloc(n,sizeof(double*));
	arrA[0] = (double*)calloc(n^2,sizeof(double));
	printf("rows of A defined\n");
	for(i = 1;i < n;i++)
	{
		arrA[i] = arrA[i-1] + n;
	}
	printf("A done\n");

	//read in second matrix
	arrB = (double**)calloc(n,sizeof(double*));
	arrB[0] = (double*)calloc(n^2,sizeof(double));
	printf("B initial declaration\n");
	for(i = 1;i < n;i++)
	{
		arrB[i] = arrB[i-1] + n;
	}
	printf("B done\n");
	
	//allocate product matrix
	arrC = (double**)calloc(n,sizeof(double*));
	arrC[0] = (double*)calloc(n^2,sizeof(double));
	printf("C initial declaration\n");
	for(i = 1;i < n;i++)
	{
		arrC[i] = arrC[i-1] + n;
	}
	printf("matrices allocated\n");
	
	printf("Size of A: %ld\n",sizeof(arrA)/sizeof(double));
	printf("Size of B: %ld\n",sizeof(arrB)/sizeof(double));
	printf("Size of C: %ld\n",sizeof(arrC)/sizeof(double));
	*/
	///////////////////////////////////////////////////////////////////
	

	//Create random matrices
        //rand_matrix(n, arrA, arrB);
	for (i = 0; i < n; i++)           
	{	
		printf("Row = %d\n",i); 	
		for (j = 0; j < n; j++)                         
		{         
			//printf("Column = %d\n",j);			
			arrA[i][j] = (double) rand() / RAND_MAX;
		       //printf("A row done\n");	
        		arrB[i][j] = (double) rand() / RAND_MAX;
			//printf("A[%d][%d] = %lf\n",i,j,arrA[i][j]);
			arrC[i][j] = 0.0;
		}
	}
	
	// Update progress
	printf("Computing matrix product(unoptimized)...\n");
	
	int ii, kk;
	
	// Begin clock
	clock_t begin, end;
	double time_spent;
	begin = clock();

	// Compute matrix product

	double  acc00, acc01, acc10, acc11;
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
	printf("--------------------------------------------------\n");

	// -----------------------------------------------------------------
	
	//****************IN PROGRESS*********************
	/*
	//Determine available memory for chunks
	int blockDim = sqrt( cacheSize / sizeof(double) ) - 3*(n^2);
	printf("Memory available for chunks: %d\n", blockDim);
	
	// Update progress
	printf("Computing matrix product(optimized)...\n");
	
	// Begin clock
	begin = clock();

	// Compute matrix product
	// *****????????*******
	
	ib = blockDim;
	kb = blockDim;
	
	// *************************

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
