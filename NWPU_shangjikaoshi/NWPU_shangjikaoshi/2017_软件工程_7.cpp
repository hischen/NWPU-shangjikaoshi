#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
#define max 10000
bool zhishu[max] = {false};
void shaifa(void)
{
	zhishu[0] = 1;
	zhishu[1] = 1;
	for (int j = 2; j <= max;j++)
	{
		if (!zhishu[j])
		{
			for (int k = 2 * j; k <= max; k = k + j)
			{
				zhishu[k] = 1;
			}
		}
	}
}
int main()
{
	shaifa();
	int zzs[20]; int i, num=0;
	for (i = 0; i < 20; i++)
	{
		scanf("%d", &zzs[i]);
	}
	for (i = 0; i < 20; i++)
	{
		if (zhishu[zzs[i]] == 0)
			num++;
	}
	cout << num << endl;
	system("pause");
	return 0;
}