#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
int main()
{
	int mat1[4][4], mat2[4][4], multiply[4][4];
	int i, j;
	fstream matrix;
	matrix.open("D:\\Github\\NWPU-shangjikaoshi\\NWPU_shangjikaoshi\\NWPU_shangjikaoshi\\matrix.txt");
	for (i = 1; i <=3; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			matrix>>mat1[i][j];
		}
	}
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			matrix >> mat2[i][j];
		}
	}
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			multiply[i][j] = mat1[i][j] * mat2[i][j];
		}
	}
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			cout << multiply[i][j] << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}