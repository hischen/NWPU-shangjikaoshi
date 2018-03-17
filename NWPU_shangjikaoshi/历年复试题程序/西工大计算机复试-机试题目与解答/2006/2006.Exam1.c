/*
	已知集合A和集合B的元素（假设为整型数据），请设计三个算法，分别计算A交B，A并B和A-B 。
	输入：
	从文件a.txt中读取集合A的数据，第一行是集合A的数据个数，第二行是集合A的元素。从文件b.txt中读取集合B的数据，
	第一行是集合B的数据个数，第二行是集合B的元素。数据之间用空格符分隔。
	输出：
	第一行是 的结果；第二行是 的结果；第三行是 的结果。
	要求：
	请使用顺序表完成本题目的算法。
	样例输入：
	6
	1 4 5 6 7 9
	7
	2 3 4 6 8 10 12
	样例输出：
	4 6
	1 2 3 4 5 6 7 8 9 10 12
	1 5 7 9
*/
/*
#include <stdio.h>

#define MAXSIZE 20

typedef struct Seqlist
{
	int Data[MAXSIZE];
	int size;
}Seqlist;

LoadData(char *fname, Seqlist* la)
{
	FILE *fp;
	int temp;
	int i=0;
	fp = fopen(fname, "rt");
	fscanf(fp, "%d\n", &la->size);
	while (!feof(fp))
	{
		fscanf(fp, "%d", &temp);
		la->Data[i++] = temp;
	}
	fclose(fp);
}

Jiao(Seqlist* la, Seqlist* lb)
{
	int i, j;
	
	for(i = 0; i < la->size; i++)
		for(j = 0; j < lb->size; j++)
			if(la->Data[i] == lb->Data[j])
				printf("%d ", la->Data[i]);
	putchar('\n');
}
Bing(Seqlist* la, Seqlist* lb)
{
	int i = 0, j = 0;
	
	while(i < la->size && j < lb->size)
	{
		if(la->Data[i] < lb->Data[j])
			printf("%d ", la->Data[i++]);
		else if(la->Data[i] == lb->Data[j])
			{		
				printf("%d ", la->Data[i]);
				i++;
				j++;
			}	
		else printf("%d ", lb->Data[j++]);
	}
	if(i < la->size)
		for(; i < la->size; i++)
			printf("%d ", la->Data[i]);
	if(j < lb->size)
		for(; j < lb->size; j++)
			printf("%d ", lb->Data[j]);
	putchar('\n');
}
Jian(Seqlist* la, Seqlist* lb)
{
	int i, j;
	
	for(i = 0; i < la->size; i++)
		for(j = 0; j < lb->size;)
		{
			if(la->Data[i] != lb->Data[j])	j++;
			else if(la->Data[i] == lb->Data[j])	break;
			if(j >= lb->size)
				printf("%d ", la->Data[i]);
		}
	putchar('\n');
}

main()
{
	Seqlist la, lb;
	LoadData("06test1-a.txt", &la);
	LoadData("06test1-b.txt", &lb);

	Jiao(&la, &lb);	
	Bing(&la, &lb);
	Jian(&la, &lb);
}

*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef struct
{
	int data[MaxSize];
	int size;
}SeqList;

void SetInterSection(SeqList la, SeqList lb, SeqList *lresult)
{
	/* Todo*/
	/* Please implement the intersection of set la and lb in the following part*/
	int i, j, k = 0;
	
	for(i = 0; i < la.size; i++)
		for(j = 0; j < lb.size; j++)
			if(la.data[i] == lb.data[j])
				lresult->data[k++] = la.data[i];
	lresult->size = k;
}

void SetUnion(SeqList la, SeqList lb, SeqList *lresult)
{
	/* Todo*/
	/* Please implement the intersection of set la and lb in the following part*/
	int i = 0, j = 0, k = 0;
	
	while(i < la.size && j < lb.size)
	{
		if(la.data[i] < lb.data[j])
			lresult->data[k++] = la.data[i++];
		else if(la.data[i] == lb.data[j])
			{			
				lresult->data[k++] = la.data[i];
				i++;
				j++;
			}	
		else lresult->data[k++] = lb.data[j++];
	}
	if(i < la.size)
		for(; i < la.size; i++)
			lresult->data[k++] = la.data[i];
	if(j < lb.size)
		for(; j < lb.size; j++)
			lresult->data[k++] = lb.data[j];
	lresult->size = k;
}

void SetSubtraction(SeqList la, SeqList lb, SeqList *lresult)
{
	/* Todo*/
	/* Please implement the intersection of set la and lb in the following part*/
	int i, j, k = 0;
	
	for(i = 0; i < la.size; i++)
		for(j = 0; j < lb.size;)
		{
			if(la.data[i] != lb.data[j])	j++;
			else if(la.data[i] == lb.data[j])	break;
			if(j >= lb.size)
				lresult->data[k++] = la.data[i];
		}
	lresult->size = k;
}

void InitList(SeqList *la)
{
	la->size =0;
}

void InsertList(SeqList *la, int x, int pos)
{
	int i;
	if (la->size == MaxSize)
	{
		printf("The list is full, we can not insert any element into the list\n");
		exit(-3);
	}
	if (pos <0 || pos > la->size)
	{
		printf("The pos is out the range\n");
		exit(-4);
	}
	for (i=la->size; i>pos; i--)
		la->data[i+1] = la->data[i];
	la->data[i] = x;
	la->size++;
}

void RemoveList(SeqList *la, int pos)
{
	int i;
	if (la->size == 0)
	{
		printf("The list is empty, we can not remove any element from the list\n");
		exit(-3);
	}
	if (pos <0 || pos >= la->size)
	{
		printf("The pos is out the range\n");
		exit(-4);
	}
	for (i=pos; i<la->size; i++)
		la->data[i] = la->data[i+1];
	la->size--;
}

int Find(SeqList *la, int x)
{
	int i=0;
	for (i=0; i<la->size; i++)
	{
		if (la->data[i] == x)
			return i;
	}
	return -1;
}

Output(char *str, SeqList la)
{
	int i;
	if (la.size == 0)
		printf("%s no element.\n", str);
	else if (la.size == 1)
		printf("%s %d element, which is \n", str, la.size);
	else
		printf("%s %d elements, which are \n", str, la.size);

	for (i=0; i<la.size; i++)
	{
		printf("%d  ", la.data[i]);
	}
	printf("\n\n");
}

void Load(char *filename, SeqList *la)
{
	FILE *fp;
	int len, i;
	fp=fopen(filename, "rt");
	if (fp==NULL)
	{
		printf("File %s can not be found \n", filename);
		exit(-1);
	}

	fscanf(fp, "%d\n", &len);
	if (len > MaxSize)
	{
		printf("The size of set is too large!!\n");
		exit(-2);
	}

	la->size=len;
	for (i=0; i<len; i++)
	{
		fscanf(fp, "%d", &la->data[i]);
	}

	fclose(fp);
}

void main()
{
	SeqList la, lb, lc, ld, le;
	Load("06test1-a.txt", &la);
	Load("06test1-b.txt", &lb);
	Output("Set A has", la);
	Output("Set B has", lb);
	InitList(&lc);
	InitList(&ld);
	InitList(&le);
	SetInterSection(la, lb, &lc);
	Output("The intersection of A and B has", lc);
	SetUnion(la, lb, &ld);
	Output("The union of A and B has", ld);
	SetSubtraction(la, lb, &le);
	Output("Set A-B has", le);
}
