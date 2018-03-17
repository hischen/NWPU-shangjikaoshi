/*
	把二进制数转换成十进制数。

	输入：
	输入是一个8位的二进制数。
	输出：
	把输入的数转换为十进制数输出。
	输入样例：
	10000001
	输出样例：
	129
*/

#include <stdio.h>

int sqrt(int x, int y)
{
	int i, num = x;

	if(y == 0)
		return 1;
	if(y == 1)
		return x;
	for(i = 1; i < y; i++)
		x = x * num;

	return x;
}

void main()
{
	char bon[8];
	int i, j, num = 0;

	for(i = 0; i < 8; i++)
		scanf("%c", &bon[i]);

	for(i = 0, j = 7; i < 8; i++, j -= 2)
		num += (bon[i] - 48) * sqrt(2, i + j);
	
	printf("%d\n", num);
}