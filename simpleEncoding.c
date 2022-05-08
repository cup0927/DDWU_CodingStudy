#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n, i, j;
	int total;
	int max = 0;
	int base = 0;
	int* p;

	scanf("%d", &n);
	p = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		scanf("%d", &p[i]);

	for (i = 0; i < n; i++) {
		total = 1;
		base = p[i] + 1;
		for (j = 0; j < n; j++) {
			if (j == i)
				total *= base;
			else
				total *= p[j];
		}
		if (total > max)
			max = total;
	}

	printf("%d", max);
	free(p);
}