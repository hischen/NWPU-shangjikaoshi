#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
using namespace std;
int max[101][101];                 //每个点能滑行的最大距离
int r, c;
int xue[101][101];                 //雪地高度值
int dirx[] = { -1,1,0,0 };            //朝x,y延伸
int diry[] = { 0,0,1,-1 };
bool edge(int x, int y)
{
	if ((x < 0) || (y < 0) || (x > r) || (y > c))
		return false;
	else return true;
	/*return  ((x > 0) && (y > 0) && (x <=r) && (y <=c));*/
}
int dp(int i, int j)
{
	int tmp;
	if (max[i][j]) return max[i][j];        //如果已经求出来了，直接返回
	for (int k = 0; k < 4; k++)
	{
		if (edge(i+dirx[k], j+diry[k]))     //判断越界
		{
			if (xue[i][j] > xue[i + dirx[k]][j + diry[k]])            //如果顺着该侧可以滑
			{
				tmp = dp(i + dirx[k], j + diry[k]);                 //递归求dp(i + dirx[k], j + diry[k])，保存至临时变量temp
				max[i][j] = max[i][j] > tmp ? max[i][j] : tmp +1;
			}
		}
	}
	return max[i][j];
}
int main()
{
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			scanf("%d", xue[i] + j);
			max[i][j] = 0;
		}
		
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cout << xue[i][j]<<' ';
		}
		cout << endl;
	}
	int temp = 0;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cout<<dp(i,j)<<' ';
			if (dp(i, j) > temp)
				temp = dp(i, j);
		}
		cout << endl;
	}
	cout << temp << endl;
	system("pause");
	return 0;
}