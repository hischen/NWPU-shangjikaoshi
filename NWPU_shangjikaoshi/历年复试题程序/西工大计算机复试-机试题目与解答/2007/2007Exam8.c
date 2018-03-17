/*
	一个给定序列的子序列是在该序列中删去若干元素后得到的序列。确切地说，
	若给定序列X=<x1, x2,…, xm>，则另一序列Z=<z1, z2,…, zk>是X的子序列
	是指存在一个严格递增的下标序列 <i1, i2,…, ik>，使得对于所有j=1,2,…,k有：

	Xij ＝ Zj

	如果一个序列S即是A的子序列又是B的子序列，则称S是A、B的公共子序列。
	求A、B所有公共子序列总最长的序列的长度。
	输入：
	输入共两行，每行一个由字母和数字组成的字符串，代表序列A、B。A、B的长度不超过10000个字符。
	输出：
	一个整数，表示最长各个子序列的长度。
	格式：printf("%d\n");
	输入样例：
	programming
	contest
	输出样例：
	2
*/

#include <stdio.h>
#define MAX 10000

int judge(char A[], char B[], int lenA, int lenB, int i, int j, int max)
{
	int len = 0;
	if(i < lenA)
	{
		if(A[i] == B[j])
		{
			max++;
			len = judge(A, B, lenA, lenB, i + 1, j + 1, max);
		}
		else if(A[i] != B[j] && j < lenB)
				len = judge(A, B, lenA, lenB, i, j + 1, max);

		else if(j >= lenB)
				len = judge(A, B, lenA, lenB, i + 1, 0, max);
			
		if(len > max) max = len;
	}
	return max;
}


void main()
{
	char A[MAX], B[MAX], ch;
	int lenA = 0, lenB = 0, maxlen = 0;
	
	scanf("%c", &ch);
	while(ch != '\n')
	{
		A[lenA++] = ch;
		scanf("%c", &ch);
	}

	scanf("%c", &ch);
	while(ch != '\n')
	{
		B[lenB++] = ch;
		scanf("%c", &ch);
	}
	
	maxlen = judge(A, B, lenA, lenB, 0, 0, maxlen);

	printf("%d\n", maxlen);
}