/*
Exam1.c
文件a和文件b中各有一组已排好序的数字，对这两组数据
进行排序，将结果输出到文件c中。例如：设文件a中为2，4，7，14；
文件b中为5，9，17；那么程序运行后文件c中应为2，4，5，7，9，14，17；
源程序已给出，在原程序的基础上按要求填写
子函数MergeList( SeqList la, SeqList lb, pSeqList lc)即可
*/

#include <stdio.h>

#define maxLen 100

typedef struct _SeqList
{
	int Data[maxLen];
	int size;
};

typedef struct _SeqList SeqList;
typedef struct _SeqList* pSeqList;

LoadData(char *fname, pSeqList la)
{
	FILE *fp;
	int temp;
	int i=0;
	fp = fopen(fname, "rt");
	while (!feof(fp))
	{
		fscanf(fp, "%d\n", &temp);
		la->Data[i++] = temp;
	}
	la->size = i;
	fclose(fp);
}

OutputData(char *fname, SeqList la)
{
	FILE *fp;
	int i;
	fp = fopen(fname, "wt");
	for (i=0; i<la.size; i++)
		fprintf(fp, "%d\n", la.Data[i]);
	fclose(fp);
}

/*
Implement the following parts as ToDo
*/

MergeList( SeqList la, SeqList lb, pSeqList lc)
{
		/*  ToDo*/
	int i = 0, j = 0, k = 0;

	while(i < la.size && j < lb.size)
	{
		if(la.Data[i] < lb.Data[j])
		{
			lc->Data[k] = la.Data[i];
			k++;
			i++;
		}	
		else 
		{
			lc->Data[k] = lb.Data[j];
			k++;
			j++;
		}
	}
	if(i < la.size)
		for(; i < la.size; i++)
			lc->Data[k++] = la.Data[i];
	if(j < lb.size)
		for(; i < lb.size; j++)
			lc->Data[k++] = lb.Data[j];
	lc->size = k;
}

main()
{
	SeqList la, lb, lc;
	LoadData("05test1-a.txt", &la);
	LoadData("05test1-b.txt", &lb);
	MergeList(la, lb, &lc);
	OutputData("c.txt", lc);

}
