#define _CRT_SECURE_NO_WARNINGS
/***************************************************************************************************/
/*装载问题
时限：1000ms 内存限制：10000K  总时限：3000ms
描述
有两艘船，载重量分别是c1、 c2.  n个集装箱，重量是wi(i = 1…n)，且所有集装箱的总重量不超过c1 + c2。确定是否有可能将所有集装箱全部装入两艘船。

输入
多个测例，每个测例的输入占两行。第一行一次是c1、c2和n（n <= 10）；第二行n个整数表示wi(i = 1…n)。n等于0标志输入结束。

输出
对于每个测例在单独的一行内输出Yes或No。

输入样例
7 8 2
8 7
7 9 2
8 8
0 0 0

输出样例
Yes
No

提示
求出不超过c1的最大值max，若总重量－max < c2则能装入到两艘船。
/***************************************************************************************************/
#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
 //集装箱编号
	int weight[11];//集装箱重量


int dp[100][100];


int max(int a, int b)
{
	return a>b ? a : b;
}
int search(int n, int w)
{
	if (n<0)
		return 0;
	if (dp[n][w] >= 0)
		return dp[n][w];
	if (w >= weight[n])
	{
		dp[n][w] = max(search(n - 1, w - weight[n]) + weight[n], search(n - 1, w));
	}
	else
		dp[n][w] = search(n - 1, w);
	return dp[n][w];
}

int main()
{

	int c1, c2, n;
	while (cin >> c1 >> c2 >> n)
	{

		if (n == 0)
			return 0;

		for (int ii = 0; ii<100; ii++)
			for (int jj = 0; jj<100; jj++)
				dp[ii][jj] = -1;

		for (int i = 0; i<n; i++)
		{
			cin >> weight[i];
		}

		int sum = 0;
		for (int j = 0; j<n; j++)
		{
			sum += weight[j];
		}


		int w1 = search(n - 1, c1);//若都装船1，能装下多少重量
		int w2 = search(n - 1, c2);//若都装船2，能装下多少O

		if ((sum - w1) <= c2)
		{
			cout << "YES" << endl;
		}
		else if ((sum - w2) <= c1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

	}
	return 0;
}



















//struct N
//{
//	int num;  //集装箱编号
//	int weight;//集装箱重量
//}st[11];
//
//int b[100][100];
//
//
//int max(int a, int b)
//{
//	return a>b ? a : b;
//}
//int search(int n, int w)
//{
//	if (n<0)
//		return 0;
//	if (b[n][w] >= 0)
//		return b[n][w];
//	if (w >= st[n].weight)
//	{
//		b[n][w] = max(search(n - 1, w - st[n].weight) + st[n].weight, search(n - 1, w));
//	}
//	else
//		b[n][w] = search(n - 1, w);
//	return b[n][w];
//}
//
//int main()
//{
//
//	int c1, c2, n;
//	while (cin >> c1 >> c2 >> n)
//	{
//
//		if (n == 0)
//			return 0;
//
//		for (int ii = 0; ii<100; ii++)
//			for (int jj = 0; jj<100; jj++)
//				b[ii][jj] = -1;
//
//		for (int i = 0; i<n; i++)
//		{
//			st[i].num = i;
//			cin >> st[i].weight;
//		}
//
//		int sum = 0;
//		for (int j = 0; j<n; j++)
//		{
//			sum += st[j].weight;
//		}
//
//
//		int w1 = search(n - 1, c1);//若都装船1，能装下多少重量
//		int w2 = search(n - 1, c2);//若都装船2，能装下多少O
//
//		if ((sum - w1) <= c2)
//		{
//			cout << "YES" << endl;
//		}
//		else if ((sum - w2) <= c1)
//		{
//			cout << "YES" << endl;
//		}
//		else
//		{
//			cout << "NO" << endl;
//		}
//
//	}
//	return 0;
//}