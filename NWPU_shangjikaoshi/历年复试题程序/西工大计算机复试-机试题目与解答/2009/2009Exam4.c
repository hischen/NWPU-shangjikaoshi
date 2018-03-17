/*
	N皇后问题
	时限：1000ms 内存限制：10000K  总时限：3000ms
	描述：
	输出N皇后问题所有不同的摆放情况个数。
	输入：
	输入一个整数n(3<n<=20),表示有n*n的棋盘，总共摆放n个皇后。
	输出：
	输出总共不同的摆放情况个数，结果单独一行。
	输入样例：
	4
	输出样例：
	2
	提示：
	输出格式为printf("%d\n",count);
*/

#include <stdio.h>
#define MAX 20

int Queen(int n)
{
	int pan[MAX][MAX] = {0}, queen[MAX] = {0};
	int i = 0, j = 0, k = 0, count = 0;

	for(i = 0; i < n; i++)
		queen[i] = i + 1;

	while(k < n)
	{
		pan[i][j] = queen[k];
		if(jadge())
	}
}

void main()
{
	int n, count;

	scanf("%d", &n);
	if(n <= 3 || n > 20)
	{
		printf("Error!\n");
		exit(0);
	}

	count = Queen(n);

	printf("%d\n",count);
}

