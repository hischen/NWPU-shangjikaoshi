/*
	你曾在山顶搭建过帐篷吗？我们面临的最大的困难莫过于在几乎全部是裸露的岩石的
	山顶找到合适的位置固定用于牵拉帐篷的钉子。
	在这个问题中，我们要搭建一座正方形的帐篷，所以我们要寻找合适的位置固定四个钉子，
	用以牵拉四帐篷的四角。此时帐篷的尺寸并不重要，但我们必须使帐篷的四角形成一个正方形，
	所以我们必须使选取的四个用于放置钉子的点构成一个正方形。现在，山顶上能够用于固定钉子的点已经被选出，
	你的任务仅仅是判断它们是否能构成一个正方形。
	输入：
	输入数据包含多个测例，tset2.txt是一个测试的数据文件。输入数据的第一行是一个整数T（1<=T<=50)，
	表示输入数据包含的测例个数。随后是各以一个空行分隔的T个测例的数据。
	每个测例包含四个选中的固定点的座标，每行有两个整数（X和Y座标）表示其中的一个点，
	两个数间由一个空格分隔，且（0<X,Y<1000)。注意，四个点不一定是按顺序给出的。
	输出：
	对于每一个独立的测例，在单独的一行内输出判断的结果，如果可以输出"Yes"，否则输出"No"。

	样例输入：
	3

	1 1
	1 2
	2 1
	2 2

	1 1
	2 2
	3 3
	4 4

	1 2
	2 1
	2 3
	3 2
	样例输出：
	Yes
	No
	Yes
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate
{
	int x;
	int y;
}coordinate;

typedef struct
{
	coordinate a;
	coordinate b;
	coordinate c;
	coordinate d;
}quadrangle;

quadrangle* LoadDate(char *filename, int *num)
{
	FILE *fp;
	int i;
	quadrangle *testdata;
	if ((fp=fopen(filename, "rt"))==NULL)
	{
		printf("File %s can not be found!\n", filename);
		exit(-1);
	}

	fscanf(fp, "%d\n\n", num);
	testdata=(quadrangle *)malloc((*num)*sizeof(quadrangle));
	for(i=0; i<(*num); i++)
	{
		fscanf(fp, "%d %d\n", &testdata[i].a.x, &testdata[i].a.y);
		fscanf(fp, "%d %d\n", &testdata[i].b.x, &testdata[i].b.y);
		fscanf(fp, "%d %d\n", &testdata[i].c.x, &testdata[i].c.y);
		fscanf(fp, "%d %d\n", &testdata[i].d.x, &testdata[i].d.y);
		fscanf(fp, "\n");
	}

	fclose(fp);
	return testdata;
}

int IsSquare(quadrangle *shape)
{
	/* Todo*/
	/* Please note: if the input shape is a square, return 1; else return 0. */
	int d1, d2, d3;

	d1 = (shape->a.x-shape->b.x) * (shape->a.x-shape->b.x) + (shape->a.y-shape->b.y) * (shape->a.y-shape->b.y);
	d2 = (shape->a.x-shape->c.x) * (shape->a.x-shape->c.x) + (shape->a.y-shape->c.y) * (shape->a.y-shape->c.y);
	d3 = (shape->a.x-shape->d.x) * (shape->a.x-shape->d.x) + (shape->a.y-shape->d.y) * (shape->a.y-shape->d.y);

	if(d1 < d2)	
	{
		if(d1 + d3 == d2)	return 1;
		else return 0;
	}
	if(d1 < d3)
	{
		if(d1 + d2 == d3)	return 1;
		else return 0;
	}
	if(d2 < d1)
	{
		if(d2 + d3 == d1)	return 1;
		else return 0;
	}
	/* Todo*/
}

main()
{
	int number;
	int i;
	int result;

	quadrangle *data;
	data = LoadDate("06test2.txt", &number);

	for (i=0; i<number; i++)
	{
		result = IsSquare(&data[i]);
		if (result)
			printf("Yes\n");
		else
			printf("No\n");
	}

	if (data != NULL)
		free(data);
}