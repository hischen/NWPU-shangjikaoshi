/*
	石子合并
	时限：1000ms 内存限制：10000K 总时限：3000ms
	描述：


	在一个圆形操场的四周摆放着n堆石子(n<= 100)，现要将石子有次序地合并成一堆。
	规定每次只能选取相邻的两堆合并成新的一堆,并将新的一堆的石子数,记为该次合并的得分.
	编一程序，读入石子堆数n及每堆的石子数(<=20)。选择一种合并石子的方案,
	使得做n－1次合并,得分的总和最小；比如有4堆石子：4 4 5 9 则最佳合并方案如下：
	4 4 5 9 score: 0
	8 5 9 score: 8
	13 9 score: 8 + 13 = 21
	22 score: 8 + 13 + 22 = 43


	输入：


	可能有多组测试数据。 当输入n=0时结束! 第一行为石子堆数n(1<=n<=100)；
	第二行为n堆的石子每堆的石子数,每两个数之间用一个空格分隔。

	输出：


	合并的最小得分，每个结果一行。

	输入样例：


	4
	4 4 5 9
	0
	输出样例：


	43

*/

#include <stdio.h>
#define MAX 100

int getscore(int n)
{
	int stone[MAX] = {0};
	int i, min, flag, score = 0;

	for(i = 0; i < n; i++)
		scanf("%d", &stone[i]);
	
	if(n == 1)	return stone[0];

	while(n > 1)
	{	
		min = stone[0] + stone[1];
		flag = 0;
		for(i = 1; i < n; i++)
			if(stone[i] + stone [(i + 1) % n] < min)
			{
				min = stone[i] + stone [(i + 1) % n];
				flag = i;
			}
		stone[flag] = min;
		score += min;
		for(i = (flag + 1) % n; i < n; i++)
			stone[i] = stone[(i + 1) % n];
		n--;
	}

	return score;

}

void main()
{
	int n;
	
	scanf("%d", &n);

	while(n != 0)
	{	
		if(n < 1 || n > 100) printf("Data is error!\n");
		else	printf("%d\n", getscore(n));
		scanf("%d", &n);
	}
}