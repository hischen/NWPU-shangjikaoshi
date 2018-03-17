/*
	约瑟夫问题
	时限：100ms 内存限制：10000K  总时限：1000ms
	描述：
	设有N名同学手拉手围成一圈，自1、2、3、......开始编号，现从1号开始连续数数，
	每数到M将此同学从圈中拉走， 求最后被拉走的同学的编号
	输入：
	两个正整数，分别为N和M。0<N<=100 ；0<M<65535
	输出：
	一个正整数，为最后被拉走的同学的编号，最后输出回车
	输入样例：
	100 10
	输出样例：
	26
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}stuNode;

stuNode* Create()
{
	stuNode* stu;

	stu = (stuNode*)malloc(sizeof(stuNode));
	if(stu == NULL)
	{
		printf("Not enough!\n");
		exit(0);
	}
	stu->data = 1;
	stu->next = stu;

	return stu;
}

void Initiate(stuNode* stu, int n)
{
	stuNode *p, *q;
	int i = 1;

	q = stu;
	while(i < n)
	{
		p = (stuNode*)malloc(sizeof(stuNode));
		if(p == NULL)
		{
			printf("Not enough!\n");
			exit(0);
		}
		p->data = i + 1;
		q->next = p;
		q = p;
		i++;
	}
	q->next = stu;
}

int Delete(stuNode* stu, int m)
{
	stuNode *p, *q;
	int i = 1;

	q = stu;
	p = stu->next;
	while(q->next != q)
	{
		if((i + 1) % m == 0)
		{
			q->next = p->next;
			free(p);
			p = q->next;
		}
		else
		{
			q = p;
			p = p->next;
		}
		i++;
	}

	return q->data;
}

void main()
{
	unsigned int N, M;
	stuNode *stu, *p, *q;
	int i;

	scanf("%d %d", &N, &M);
	if(N > 100)
		printf("Error!\n");	

	stu = Create();
	Initiate(stu, N);
	printf("%d\n", Delete(stu, M));
}