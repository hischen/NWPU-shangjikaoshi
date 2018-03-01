#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<stdio.h>  
void printYangHui();
int main()
{
	printYangHui();//  
	system("pause");
	return 0;
}
void printYangHui()//按行数打印杨辉三角  
{
	int rows, coef = 1, space, i, j;
	printf("行数: ");
	scanf("%d", &rows);

	//控制行数  
	for (i = 0; i<rows; i++)
	{
		//打印空格  
		for (space = 1; space <= rows - i; space++)
			printf("  ");
		//  
		for (j = 0; j <= i; j++)//第n行的数字有n项，所以j<=i  
		{
			//第一行为1，第一列为1  
			if (j == 0 || i == 0)
				coef = 1;
			else
				coef = coef * (i - j + 1) / j;//最后一个每一行i=j,倒数第二行（coef=j）等于列数，  
			printf("%4d", coef);
		}
		printf("\n");
	}

}
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