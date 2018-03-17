/*
	已知k阶裴波那契数列的定义为f0=0，f1=0，…，fk-2=0, fk-1=1； fn=fn-1+fn-2+…+fn-k，n=k，k+1，…，
	试编写求k阶裴波那契数列的第m项值的函数算法，k和m均以值调用的形式在函数参数表中出现。
	输入数据：输入两个正整数k m(其中1<k<m，本题所有数据都在长整形数据的范围之内)
	输出数据：输出k阶裴波那契数列的第m项值fm。
	（注意：本题所涉及的所有数据都在长整形数据的范围之内）
	Sample input
	2 3
	Sample output
	2
*/

#include <stdio.h>
#define MAXSIZE 100

int feibonaqi(long int k, long int m)
{
	int i, j, count = 0, f[MAXSIZE] = {0};

	f[k - 1] = 1;
	for(i = k; i <= m; i++)
		for(j = i - k; j < i; j++)
			f[i] += f[j];
	return f[m];
}

void main()
{
	long int k, m;

	scanf("%d %d", &k, &m);
	if(k <= 1 || k >= m)
	{
		printf("Input Error!\n");
		exit(0);
	}

	printf("%d\n", feibonaqi(k, m));
}