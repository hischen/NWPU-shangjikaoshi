#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

queue<int>q1;

int sum = 0, t, use[1000000];
void init();
int bfs();
int change1(int n);
int change2(int n);

int main()
{
	int a[6], i, j;
	while (scanf_s("%d", &a[0]) != EOF)
	{
		sum = 0;
		for (int k = 100000; k <= 654321; k++)
		{
			use[k] = 0;
		}
		for (i = 1; i<6; i++)
		{
			scanf_s("%d", &a[i]);
		}
		for (j = 0; j<6; j++)//将数组转化为一个六位数存起来比较方便
		{
			sum = sum * 10 + a[j];
		}
		init();
		if (bfs() == 1)printf("Yes\n");
		else if (bfs() == -1)printf("No\n");
		while (!q1.empty())
		{
			q1.pop();//每次输入数据得出结论后都要将队列中的元素清空，避免影响
		}

	}
	return 0;
}
void init()//初始化，第一个数进队列
{
	q1.push(sum);
	use[sum] = 1;//标记此数据已用过
}
int bfs()
{
	int u, v, i;
	while (!q1.empty())
	{
		u = q1.front();
		q1.pop();
		if (u == 654321)
		{
			return 1;
		}
		for (i = 0; i<2; i++)
		{
			if (i == 0)v = change1(u);
			else if (i == 1)v = change2(u);
			if (use[v] != 1)
			{
				q1.push(v);//v进入对列
				use[v] = 1;//标记v已被用过
			}
		}
	}
	return -1;
}
int change1(int n)//将六位数转化成数组在按照规定转化得到另一个六位数返回
{
	int a[6], y[6];
	int i, s = 0;
	for (i = 5; i >= 0; i--)
	{
		a[i] = n % 10;
		n = n / 10;
	}
	y[2] = a[1];
	y[5] = a[2];
	y[4] = a[5];
	y[1] = a[4];
	y[3] = a[3];
	y[0] = a[0];
	for (i = 0; i<6; i++)
	{
		s = s * 10 + y[i];
	}
	return s;

}
int change2(int n)
{
	int a[6], y[6];
	int i, s = 0;
	for (i = 5; i >= 0; i--)
	{
		a[i] = n % 10;
		n = n / 10;
	}
	y[1] = a[0];
	y[3] = a[4];
	y[4] = a[1];
	y[0] = a[3];
	y[2] = a[2];
	y[5] = a[5];
	for (i = 0; i<6; i++)
	{
		s = s * 10 + y[i];
	}
	return s;
}

