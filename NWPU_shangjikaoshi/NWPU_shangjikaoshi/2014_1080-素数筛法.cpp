#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define max 10001
bool mark[max] = { 0 };
void shai()
{
	mark[0] = 1;
	mark[1] = 1;
	for (int i = 2; i <= max; ++i)
	{
		if (!mark[i])
		{
			for (int j = 2 * i; j <= max; j += i)
			{
				mark[j] = 1;
			}
		}
	}
}
int main()
{
	shai();
	int input1, input2;
	scanf("%d %d", &input1, &input2);
	for (int k = input1; k <= input2; k++)
	{
		if (!mark[k]) printf("%d\n", k);
	}
	system("pause");
	return 0;
}