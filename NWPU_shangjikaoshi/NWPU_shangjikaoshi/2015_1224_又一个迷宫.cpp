#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int N;
	scanf_s("%d", &N, sizeof(N));
	int i, j;
	int m, n;
	int direction;
	int maze[100][100];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &maze[i][j]);
		}
	}
	scanf_s("%d %d", &m, &n,sizeof(m));
	scanf("%d", &direction);
	switch (direction)
	{
	case 3: {if (m != 0 && maze[m - 1][n] != 1) printf("Y\n"); else printf("N\n"); }break;
	case 1: {if (m != N-1 && maze[m + 1][n] != 1) printf("Y\n"); else printf("N\n"); }break;
	case 0: {if (n != 0 && maze[m][n-1] != 1) printf("Y\n"); else printf("N\n"); }break;
	case 2: {if (m !=N-1 && maze[m][n+1] != 1) printf("Y\n"); else printf("N\n"); }break;
	default:
		break;
	}
	system("pause");
	return 0;
}