#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "headers.h"

//void rand_matrix();

int main(int argc, char *argv[])
{

	// Get cache size of computer
	int cacheSize = getCacheSize();
        printf("Cache size of this computer's processor: %d Bytes\n", cacheSize);

	// Update progress
	printf("Initializing matrices...\n");
	
	int rA,cA,rB,cB;
	int i,j,k;
	
	FILE *A,*B,*C;
	A = fopen(argv[1],"r");
	B = fopen(argv[2],"r");
	
	int **arrA,**arrB,**arrC,num;
	
	//read in first matrix
	fscanf(A,"%d %d \n",&rA,&cA);
	arrA = (int**)calloc(rA,sizeof(int*));
	arrA[0] = (int*)calloc(rA*cA,sizeof(int));
	for(i = 1;i < rA;i++)
	{
		arrA[i] = arrA[i-1] + cA;
	}
	for(j = 0;j < rA;j++)
	{
		for(k = 0;k < cA; k++)
		{
			fscanf(A,"%d",&num);
			arrA[j][k] = num;
		}
	}	
	
	//read in second matrix
	fscanf(B,"%d %d \n",&rB,&cB);
	arrB = (int**)calloc(rB,sizeof(int*));
	arrB[0] = (int*)calloc(rB*cB,sizeof(int));
	for(i = 1;i < rB;i++)
	{
		arrB[i] = arrA[i-1] + cB;
	}
	for(j = 0;j < rA;j++)
	{
		for(k = 0;k < cA;k++)
		{
			fscanf(B,"%d",&num);
			arrB[j][k] = num;
			//printf("arrB[%d][%d] = %lf \n",j,k,num);
		}
	}

	arrC = (int**)calloc(rA,sizeof(int*));
	arrC[0] = (int*)calloc(rA*rB,sizeof(int));
	for(i = 1;i < rA;i++)
	{
		arrC[i] = arrC[i-1] + cA;
	}
	for(j = 0;j < rA;j++)
	{
		for(k = 0;k < cA;k++)
		{
			arrC[j][k] = 0;
			//printf("arrC[%d][%d] = %lf\n",j,k,arrC[j][k]);
		}
	}

	// Iterators
	int  ii, kk;

	// Create random matrices
	//rand_matrix();

	// Update progress
	printf("Computing matrix product...\n");
	
	// Begin clock
	clock_t begin, end;
	double time_spent;
	begin = clock();

	// Compute matrix product
	
	//size of matrices asssuming same size and 
	int n;
	n = rA;

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
	printf("Time spent computing matrix product: %lf\n",time_spent);
	
	printf("Matrix Product: \n");
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			printf("%d ",arrC[i][j]);
		}
		printf("\n");
	}		

	free(arrA);
	free(arrB);
	free(arrC);

	return 0;
}

//void rand_matrix()
//{
//	int i, j;
//	srand ( time(NULL) );
//	
//	for (i = 0; i < n; i++)
//	{		
//		for (j = 0; j < n; j++)
//		{
//			A[i][j] = (double) rand() / RAND_MAX;
//			B[i][j] = (double) rand() / RAND_MAX;
//		}
//	}
//}
