////소스코드2: 행렬 연산

//상이한 크기의 행렬을 get_data() 함수로 처리하는 문제를 해결하기 위한 class 사용
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5
/*
행렬이 여러개 일 때 하나의 function으로 처리하는 방법을 고안
*/

int get_data(int*p, int m, int n)
{
	int var = m * n;

	// 방법 1.
	//for (int i = 0; i < var; i++)
	//	p[i] = rand() % var;
	//return 1;
	// 방법 2.
	for (int i=0; i < m; i++)
		for (int j = 0; j < n; j++)
			p[i * n + j] = rand() % var;
	return 0;
}

void show_data(int*p, int m, int n)
{
	/*for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", p[m][n]);
		printf("\n");
	}*/

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%3d ", p[i * n + j]);
		printf("\n");
	}
	printf("\n");
}

void multiply(int *p1, int ar, int ac, int *p2, int bc, int *p3, int cr, int cc) 
{
	for (int i = 0; i < ar; i++)
	{
		for (int j = 0; j < cc; j++)
		{
			p3[bc * i + j] = 0;
			//printf("[%d*%d]", i, j);

			for (int k = 0; k < ac; k++)
			{
				p3[bc * i + j] += p1[ac*i+k] * p2[bc*k+j];
				//printf("%d*%d ", ac * i + k, bc * k + j); 
			}
			//printf("\n");
		}	
	}
}
int main(void)
{
	int matrixA[AROWS][ACOLS];
	int matrixB[BROWS][BCOLS];
	int matrixC[CROWS][CCOLS];

	srand(time(NULL));
	get_data((int*)matrixA, AROWS, ACOLS);
	show_data((int*)matrixA, AROWS, ACOLS);
	get_data((int*)matrixB, BROWS, BCOLS);
	show_data((int*)matrixB, BROWS, BCOLS);

	multiply((int*)matrixA, AROWS, ACOLS, (int*)matrixB, BCOLS, (int*)matrixC, CROWS, CCOLS);
	show_data((int*)matrixC, CROWS, CCOLS);
	system("pause");
	return 0;
}
