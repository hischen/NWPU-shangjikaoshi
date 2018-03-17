#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
using namespace std;
#include <stdio.h>
int n;
int main()
{
	int i, j, k;
	int a[2000];
	for (i = 0; i<2000; i++)
		a[i] = 0;
	for (i = 2; i <= 1000; i++)
	{
		for (j = 1; j<10; j++)//注意：是大于0，小于10 
		{
			if (i - j>0)
			{
				if (a[i - j] == 0) //找到上一个“9滑动窗口”中为0的情况，然后将此次的取法转化为上次的情况。
					a[i] = j;
			}
			else { break; }
		}
	}
	scanf("%d", &n);

	while (n != 0)
	{
		printf("%d\n", a[n]);
		scanf("%d", &n);
	}
	return 0;
}