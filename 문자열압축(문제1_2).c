#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, j, k;
	int len = 0;
	int count;
	char key[2];
	char s[1000];
	char compressed[1000];

	scanf("%s", s);

	i = 0;
	k = 0;
	while (s[i] != '\0') {
		count = 0;
		key[0] = s[i];
		key[1] = s[i+1];
		for (j = i; s[j] != '\0'; j+=2) {
			if (s[j] == key[0] && s[j+1] == key[1])
				count++;
			else
				break;
		}
		if (count == 1) {
			compressed[k++] = s[i];
			compressed[k++] = s[i+1];
			i+=2;
		}
		else {
			compressed[k++] = 48 + count;
			compressed[k++] = key[0];
			compressed[k++] = key[1];
			i = j;
		}
	}
	compressed[k] = '\0';

	printf("%s\n", compressed);

	len = strlen(compressed);
	printf("%d", len);
}