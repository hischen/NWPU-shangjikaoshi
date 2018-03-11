#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
int fibonacci[25];//将斐波那契数放在这个数组
void creatfbnq()
{
	fibonacci[1] = 1;
	fibonacci[2] = 1;
	for (int m = 3; m <= 25; m++)
	{
		fibonacci[m] = fibonacci[m - 1] + fibonacci[m - 2]; //得到斐波那契数列
	}
}
int largefbnq(int n) //返回小于n的最大斐波那契数
{
	int d;
	for (d = 1; d <= 50; d++)
	{
		if (fibonacci[d]<n&&fibonacci[d + 1]>n)
			break;
	}
	return fibonacci[d];
}
bool is_fbnq(int n)                           //判断整数n是否为斐波那契数
{
	for (int c = 1; c <= 25; c++)
	{
		if (fibonacci[c] == n)
			return 1;
	}
	return 0;
}
int main()
{
	int n;
	creatfbnq();
	while (scanf("%d", &n) != EOF && n <= 10000 && n > 0)
	{
		int fbnqbs[25];
		int i = 0;
		if (is_fbnq(n))
		{
			cout << n << endl;
			continue;
		}
		else
		{	
			while (!is_fbnq(n))
			{
				int temp=largefbnq(n);
				n = n - temp;
				fbnqbs[i++] = temp;
			}
			fbnqbs[i++] = n;
		}
		for (int e = 0; e < i; e++)
		{
			if (e == i - 1) cout << fbnqbs[e]<<endl;
			else cout << fbnqbs[e] << '+';
		}
		//cout << endl;
		
	}
	return 0;
}