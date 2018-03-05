#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<stdio.h>  
#include <iostream>  
using namespace std;
#include <iostream>  
using namespace std;
int fun(int n, int k)//n为行，k为列  
{
	if (k == 1 || n == k)//每行第一列||最后一列；每行端点与结尾  
		return 1;
	else
		return fun(n - 1, k - 1) + fun(n - 1, k);//计算公式  
}
int main()
{
	int n;
	while (1)
	{
		cout << "请输入n：";
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int k = 1; k<n - i + 1; k++)
				cout << "  ";
			for (int j = 1; j <= i; j++)
				//cout << fun(i, j) << " ";
				printf("%4d", fun(i,j));
			cout << endl;
		}
	}
	return 0;
}
/*输入行数n，列数m.得到该行该列的值****************************************************/
//int fun(int n, int k)//n为行，k为列  
//{
//	if (k == 1 || n == k)//每行第一列||最后一列；每行端点与结尾  
//		return 1;
//	else
//		return fun(n - 1, k - 1) + fun(n - 1, k);//计算公式  
//}
//int main()
//{
//	int n,m;
//	while (1)
//	{
//		//cout << "请输入行：";
//		cin >> n>>m;
//			cout << fun(n, m)<<endl;
//		
//	}
//	return 0;
//}
/************************************************************************************/

/**********************************************************************/
//通过组合公式推导，可得等效的迭代表达dwTriVal = dwTriVal * (dwRow - dwCol) / (dwCol + 1)。
void BinomialYangHui(void)
{
	int dwRow = 0, dwCol = 0, dwTriVal;

	for (dwRow = 0; dwRow < MAX_ROW; dwRow++)
	{   //首列直接输出1，否则由二项式系数递推公式求出杨辉值
		dwTriVal = 1;
		for (dwCol = 0; dwCol <= dwRow; dwCol++)
		{
			printf("%5d", dwTriVal);
			dwTriVal = dwTriVal * (dwRow - dwCol) / (dwCol + 1);
		}
		printf("\n");
	}
}
void printYangHui()//按行数打印杨辉三角  
{
	int rows, coef = 1, space, i, j;
	printf("行数: ");
	scanf("%d", &rows);
	for (i = 0; i<rows; i++)
	{
		coef = 1;
		for (space = 1; space <= rows - i; space++)
			printf("  ");
		for (j = 0; j <= i; j++)//第n行的数字有n项，所以j<=i  
		{
			printf("%5d", coef);
			coef = coef * (i - j) / (j + 1);
		}
		printf("\n");
	}

}
/**********************************************************************/
//void printYangHui();
//int main()
//{
//	printYangHui();//  
//	system("pause");
//	return 0;
//}
//void printYangHui()//按行数打印杨辉三角  
//{
//	int rows, coef = 1, space, i, j;
//	printf("行数: ");
//	scanf("%d", &rows);
//
//	//控制行数  
//	for (i = 0; i<rows; i++)
//	{
//		//打印空格  
//		for (space = 1; space <= rows - i; space++)
//			printf("  ");
//		//  
//		for (j = 0; j <= i; j++)//第n行的数字有n项，所以j<=i  
//		{
//			//第一行为1，第一列为1  
//			if (j == 0 || i == 0)
//				coef = 1;
//			else
//				coef = coef * (i - j + 1) / j;//最后一个每一行i=j,倒数第二行（coef=j）等于列数，  
//			printf("%4d", coef);
//		}
//		printf("\n");
//	}
//
//}
//int main()
//{
//	int a[100][200], i, j, n;
//	printf("请输入n值：\n");
//	scanf("%d", &n);
//
//	for (i = 0; i<100; i++)
//		for (j = 0; j<200; j++)
//			a[i][j] = 0;
//
//	for (i = 0; i<n; i++)
//	{
//		for (j = n - 1 - i; j <= i + 5; j = j + 2)
//		{
//			if (j<n - i)
//				a[i][j] = 1;
//			else
//				a[i][j] = a[i - 1][j - 1] + a[i - 1][j + 1];
//		}
//	}
//
//	for (i = 0; i<n; i++)
//	{
//		for (j = 0; j <= i + 5; j++)
//		{
//			if (a[i][j] == 0)
//				printf("    ");
//			else
//				printf("%3d ", a[i][j]);
//		}
//		
//		printf("\n");
//	}
//
//	system("pause");
//}