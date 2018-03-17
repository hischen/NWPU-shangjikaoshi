/*
	矩阵中比上下两个数都大且比左右两个数都小或者比上下两个数都小且比左右两个数都大的数成为"鞍点"。求输入的矩阵中鞍点的个数。

	输入：
	输入的第一行是两个整数m、n，代表矩阵有m行n列；
	接下来的m行每行有n个正整数。
	输出：
	输出鞍点的个数。格式是printf("%d\n", count);
	输入样例：
	3 4
	1 2 3 4
	6 5 8 7
	4 3 2 1
	输出样例：
	1
*/

#include <stdio.h>
#define MAXSIZE 10

int judgeOne(int array[][MAXSIZE], int i, int j, int m, int n)
{
	if((array[i][j] > array[(i + m - 1) % m][j] && array[i][j] > array[(i + 1) % m][j]) 
		&& (array[i][j] < array[i][(j + 1) % n] && array[i][j] < array[i][(j + n - 1) % n]))
		return 1;
	else return 0;
}

int judgeTwo(int array[][MAXSIZE], int i, int j, int m, int n)
{
	if((array[i][j] < array[(i + m - 1) % m][j] && array[i][j] < array[(i + 1) % m][j]) 
		&& (array[i][j] > array[i][(j + 1) % n] && array[i][j] > array[i][(j + n - 1) % n]))
		return 1;
	else return 0;
}

void main()
{
	int array[MAXSIZE][MAXSIZE] = {0};
	int i, j, m, n, count = 0;

	scanf("%d %d", &m, &n);

	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &array[i][j]);
	
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			if(judgeOne(array, i, j, m, n) || judgeTwo(array, i, j, m, n))
				count++;

	printf("%d\n", count);
}