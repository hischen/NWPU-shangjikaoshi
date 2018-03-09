#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char s[80];
	char num[80];
	int k = 0;
	scanf("%s", s);
	for (int i = 0; s[i]!='\0'; i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			num[k++] = s[i];
		}

	}
	for (int j = 0; j<=k; j++)
	{
		cout << num[j]<<endl;
	}
	//printf("%s", num);
	system("pause");
	return 0;
}