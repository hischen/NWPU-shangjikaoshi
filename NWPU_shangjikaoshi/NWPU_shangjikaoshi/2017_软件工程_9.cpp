#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include <stdlib.h>
using namespace std;
int main()
{
	float chengji[40];
	int i = 1, n = 0;
	float sum = 0, ave = 0;
	int bujige = 0, youxiu = 0;
	do
	{
		scanf("%f", &chengji[i++]);
		n++;
	} while (getchar() != '\n');
	
	for (i = 1; i <= n; i++)
	{
		//cout << chengji[i] << endl;
		sum+=chengji[i];
		if(chengji[i]<60) bujige++;
		else if (chengji[i]>=90) youxiu++;
		
	}
	//cout << sum << ' ' << n << endl;
	ave = sum / n;
	cout << "学生平均成绩为" << ave << endl;
	cout << "不及格学生数量为：" << bujige << endl;
	cout<<"成绩优秀学生数量为："<<youxiu<<endl;
	system("pause");
	return 0;
}