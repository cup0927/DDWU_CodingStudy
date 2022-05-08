#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void readMatrix(int a[][3])
{
	int c, r;
	for (c = 0; c < 3; c++) {
		for (r = 0; r < 3; r++) {
			scanf("%d", &a[c][r]);
		}
	}
}

void matrixAdd(int a[][3], int b[][3], int x[][3])
{
	int c, r;
	for (c = 0; c < 3; c++)
		for (r = 0; r < 3; r++)
			x[c][r] = a[c][r] + b[c][r];
}

void printMatrix(int a[][3])
{
	int c, r;
	for (c = 0; c < 3; c++) {
		for (r = 0; r < 3; r++)
			printf("%3d ", a[c][r]);
		printf("\n");
	}
}

int main(void)
{
	int a[3][3];
	int b[3][3];
	int x[3][3];
	
	printf("(3x3) 행렬 A 입력:\n");
	readMatrix(a);
	printf("(3x3) 행렬 B 입력:\n");
	readMatrix(b);

	matrixAdd(a, b, x);

	printf("행렬합: \n");
	printMatrix(x);
}