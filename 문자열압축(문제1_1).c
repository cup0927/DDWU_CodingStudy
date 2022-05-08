#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, j, k;
	int len = 0;
	int count, key;
	char s[1000];
	char compressed[1000];
	
	scanf("%s", s);

	i = 0;
	k = 0;
	while(s[i] != '\0') {
		count = 0;
		key = s[i];
		for (j = i; s[j] != '\0'; j++) {
			if (s[j] == key)
				count++;
			else
				break;
		}
		if (count == 1) {
			compressed[k++] = s[i];
			i++;
		}
		else {
			compressed[k++] = 48+ count;
			compressed[k++] = key;
			i = j;
		}
	}
	compressed[k] = '\0';

	printf("%s\n", compressed);

	len = strlen(compressed);
	printf("%d", len);
}