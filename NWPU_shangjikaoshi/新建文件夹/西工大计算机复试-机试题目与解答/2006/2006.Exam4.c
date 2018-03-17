/*
	有两艘船，载重量分别是c1、c2，n个集装箱，重量是wi (i=1…n)，
	且所有集装箱的总重量不超过c1+c2。确定是否有可能将所有集装箱全部装入两艘船。

	输入：
	从文件test4.txt中加在测试数据。
	先输入一个整数m，然后输入m组测试数据。
	每组测试数据将包含一列正整数，每行只有一个数字。先输入三个整数c1、 c2，n。然后输入n个集装箱的重量。
	输出：
	Yes或No，每个输出占一行。

	样例输入：
	2
	50
	39
	3
	27
	20
	35
	100
	200
	2
	201
	5
	样例输出：
	Yes
	No
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int c1;
	int c2;
	int n;
	int *p;
} Sample;


Sample* LoadData(char *filename, int *SampleNum)
{
	FILE *fp;
	int i;
	int j;
	int number;
	Sample *testdata;

	if ((fp=fopen(filename, "rt"))==NULL)
	{
		printf("File %s can not be found!\n", filename);
		exit(-1);
	}
	fscanf(fp, "%d\n\n", SampleNum);
	testdata=(Sample *)malloc((*SampleNum)*sizeof(Sample));
	for(i=0; i<(*SampleNum); i++)
	{
		fscanf(fp, "%d\n", &testdata[i].c1);
		fscanf(fp, "%d\n", &testdata[i].c2);
		fscanf(fp, "%d\n", &testdata[i].n);
		
		testdata[i].p=(int*)malloc(testdata[i].n*sizeof(int));
		for (j=0; j<testdata[i].n; j++)
		{
			fscanf(fp, "%d\n", &testdata[i].p[j]);
		}
	}

	fclose(fp);
	return testdata;
}

int CanLoading(Sample data)
{
	/* Todo*/
	/* Please note: if the data can be loaded, return 1; else return 0. */
	int i, count = 0, flag = 1;

	for(i = 0; i < data.n; i++)
	{
		count += data.p[i];
		if(data.p[i] > data.c1 || data.p[i] > data.c2)
			flag = 0;
	}
	if(count > data.c1 + data.c2 || flag == 0)
		return 0;
	else return 1;
	/* Todo*/
}

void main()
{

	int i, j, count;
	Sample * data;
	data = LoadData("06test4.txt", &count);
	for(i=0; i<count; i++)
	{
		if (CanLoading(data[i]))
			printf("Yes\n");
		else
			printf("No\n");
	}

	/*free memory */

	for(i=0; i<count; i++)
	{
		if (data[i].p != NULL)
		{
			free(data[i].p);
			data[i].p = NULL;
		}
	}

	if (data != NULL)
	{
		free(data);
		data = NULL;
	}
	/*free memory */

}
