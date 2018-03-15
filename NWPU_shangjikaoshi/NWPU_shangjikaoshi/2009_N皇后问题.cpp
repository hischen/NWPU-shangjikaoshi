#include<stdio.h>
int count=0;
//参数row:表示起始行
//参数n:表示列数
//参数(*chess)[8]：表示指向棋盘每一行的指针
bool notdanger(int row, int j, int(*chess)[8])
{
	int i,k, flag1 = 0; int flag2 = 0; int flag3 = 0; int flag4 = 0;
	//pan duan lie fx
	for (i = 0; i < 8; i++)
	{
		if (*(*(chess + i) + j) != 0)
		{
			flag1 = 1;
			break;
		}
	}
	//判断左上方
	for (i = row, k = j; i >= 0 && k >= 0; i--, k--)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag2 = 1;
			break;
		}
	}
	//判断右下方
	for (i = row, k = j; i<8 && k<8; i++, k++)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag3= 1;
			break;
		}
	}
	//判断右上方
	for (i = row, k = j; i>=0 && k<8; i--, k++)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag4 = 1;
			break;
		}
	}
	//判断右上方
	for (i = row, k = j; i >= 8 && k<8; i--, k++)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag4 = 1;
			break;
		}
	}
}
void eightqueen(int row,int n,int (*chess)[8])//指向棋盘每一行的指针
{
	int chess2[8][8],i,j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			chess2[i][j] = chess[i][j];
		}
		if (8 == row)
		{
			printf("第 %d 种",count + 1);
			for (i = 0; i < 8; i++)
			{
				for (j = 0; j < 8; j++)
				{
					printf("%d", *(*chess2 + i) + j);
				}
				printf("\n");
			}
		printf("\n");
		count++;
		}
			else
		{
				//判断这个位置是否有危险。如果没有危险？继续往下
				for (j = 0; j < n; j++)
				{
					if (notdanger(row,j.chess))//判断是否有危险
					{
						for (i = 0; i < 8; i++)
						{
							*(*(chess2 + row) + i) = 0;
						}
						*(*(chess2 + row) + j) = 1;
						eightqueen(row + 1, n, chess2);
					}
				}
		}
	}
}             
int main()
{
	int chess[8][8], i, j;
	for (i = 0; i < 8; i++)    //棋盘初始化
	{
		for (j = 0; j < 8; j++)
		{
			chess[i][j] = 0;
		}
	}
	eightqueen();
	return 0;
}