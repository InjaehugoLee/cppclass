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

int get_data(int*p, int ar, int ac)
{
	for (int i = 0; i < ar*ac; i++)
		p[i] = rand() % (ar * ac);
	return 1;
}
void show_data(int*p, int ar, int ac)
{
	for (int i = 0; i < ar; i++)
	{
		for (int j = 0; j < ac; j++)
			printf("%d ", p[ac*i+j]);
		printf("\n");
	}
}
void multiply(int* p1, int ar, int ac, int* p2, int br, int bc, int* p3, int cr, int cc) {

	for (int i = 0; i < ar; i++)
	{
		for (int j = 0; j < cc; j++)
		{
			p3[cc * i + j] = 0;
			for (int k = 0; k < br; k++)
			{
				p3[cc * i + j] += p1[ar * i + k] * p2[bc * k + j];
			}
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
	printf("\n");
	get_data((int*)matrixB, BROWS, BCOLS);
	show_data((int*)matrixB, BROWS, BCOLS);
	printf("\n");
	multiply((int*)matrixA, AROWS, ACOLS, (int*)matrixB, BROWS, BCOLS, (int*)matrixC, CROWS, CCOLS);
	show_data((int*)matrixC, CROWS, CCOLS);
	system("pause");
	return 0;
}