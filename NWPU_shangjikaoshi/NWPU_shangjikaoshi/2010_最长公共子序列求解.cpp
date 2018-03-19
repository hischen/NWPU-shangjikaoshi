#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char a[30], b[30];
int lena, lenb;
int LCS(int i, int j);//两个参数分别表示数组a的下标和数组b的下标

int main()
{
	//strcpy(a, "ABCBDAB");
	//strcpy(b, "BDCABA");
	while (cin >> a >> b)
	{
		lena = strlen(a);
		lenb = strlen(b);
		printf("%d\n", LCS(0, 0));
	}
	system("pause");
	return 0;
}

int LCS(int i, int j)
{
	if (i >= lena || j >= lenb)
		return 0;
	if (a[i] == b[j])
		return 1 + LCS(i + 1, j + 1);
	else
		return LCS(i + 1, j)>LCS(i, j + 1) ? LCS(i + 1, j) : LCS(i, j + 1);
}