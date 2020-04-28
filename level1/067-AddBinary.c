/*
* @Author: Cheng.Wang
* @Date:   2020-04-28 16:21:39
* @Last Modified by:   Cheng.Wang
* @Last Modified time: 2020-04-28 17:46:20
* @Email:   cheng.wang@amlogic.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * addBinary(char * a, char * b){

	char cc;
	int z = 0, c = 0;
	int len1 = strlen(a) - 1 , len2 = strlen(b) - 1;
	char *re = (char *)malloc(sizeof(char) * 1001);
	printf("%d %d\n", len1, len2);
	while(1) {
		printf("----\n");
		c += len1 - 1 > -1? a[len1 - 1] - '0': 0;
		c += len2 - 1 > -1? b[len2 - 1] - '0': 0;
		re[z++] = c % 2 + '0';
		c /= 2;
		len1--;
		len2--;
		if (len1 < 0 && len2 < 0 && c == 0)
			break;
	}

	re[z] = '\0';

	for (int i = 0, j = z - 1; i < j ; i++, j--)
		cc = re[i], re[i] = re[j], re[j] = cc;

	return re;
}

int main(int argc, char const *argv[])
{
	/* code */
	char *a = (char *)malloc(sizeof(char) * 4);
	char *b = (char *)malloc(sizeof(char) * 4);
	char *c = (char *)malloc(sizeof(char) * 10);
	// for (int i = 0; i < 10; i++)
	a[0] = '1';
	a[1] = '1';
	a[2] = '1';
	a[3] = '0';

	b[0] = '1';
	b[1] = '1';
	b[2] = '1';
	b[3] = '1';

	// for (int i = 0; i < 10; i++)
	// 	printf("%c ", a[i]);
	c = addBinary(a, b);
	for (int i = 0; c[i] != '\0'; i++)
		printf("%c ", c[i]);

	return 0;
}