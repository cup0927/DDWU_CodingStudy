#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void readMatrix(int** a, int r, int c)
{
	int i, j;
	for (i = 0; i < c; i++) {
		for (j = 0; j < r; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}
void matrixAdd(int **a, int **b, int **x, int r, int c)
{
	int i, j;
	for (i = 0; i < c; i++) {
		for (j = 0; j < r; j++) {
			x[i][j] = a[i][j] + b[i][j];
		}
	}

}
void printMatrix(int **a, int r, int c)
{
	int i, j;
	for (i = 0; i < c; i++) {
		for (j = 0; j < r; j++) 
			printf("%3d ", a[i][j]);
		printf("\n");
	}
}
int main(void)
{
	int** A, ** B;
	int** X;
	int aRow, aCol;
	int i, j;

	printf("Enter 행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &aRow, &aCol);

	A = (int**)malloc(sizeof(int*) * aCol);
	for (i = 0; i < aCol; i++)
		A[i] = (int*)malloc(sizeof(int) * aRow);

	B = (int**)malloc(sizeof(int*) * aCol);
	for (i = 0; i < aCol; i++)
		B[i] = (int*)malloc(sizeof(int) * aRow);

	X = (int**)malloc(sizeof(int*) * aCol);
	for (i = 0; i < aCol; i++)
		X[i] = (int*)malloc(sizeof(int) * aRow);

	printf("(%dx%d) 행렬 A 입력:\n", aCol, aRow);
	readMatrix(A, aCol, aRow);
	printf("(%dx%d) 행렬 B 입력:\n", aCol, aRow);
	readMatrix(B, aCol, aRow);

	matrixAdd(A, B, X, aCol, aRow);

	printf("행렬합:\n");
	printMatrix(X, aCol, aRow);
	printf("\n");

	for (i = 0; i < aCol; i++) {
		free(A[i]);
		free(B[i]);
		free(X[i]);
	}
	free(A);
	free(B);
	free(X);
}