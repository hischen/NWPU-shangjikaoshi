/*
阅读下列函数说明和C代码，将应填入其中横线处的字句，写在答案的对应栏内。
随后上机调试程序，得到相应结果。（30分）
读入一批以负数为结束的正整数，数据为5，7，2，4，9，－1，
建立一个带头结点的链表，链表的每个结点中包含有两个指针：一个用于链接输入的先后顺序，
另一个用于链接输入整数从小到大的顺序。并分别按两个指针方向进行遍历输出。
*/

#include <stdio.h>
#include<stdlib.h>

typedef struct NODE
{	int val  ;
	struct NODE *order;
	struct NODE *sort;
}NODE;

void main( )
{	NODE *h,*u,*v,*p,*tail;
	int d;

	h=(NODE *)malloc(sizeof(NODE));
	tail=h;
	tail->sort=NULL;

	printf("Please input data:");
	do
	{		
		scanf("%d",&d);
		if(d>0)
		{
			p=(NODE *)malloc(sizeof(NODE));
			p->val=d;
			tail->order = p;	//空1
			tail=p;
			for(u=h,v=u->sort; v&&v->val<d; v = v->sort, u = u->sort/*空2*/);
			p->sort=v;
			u->sort = p;	//空3
		}
	}while(d>0);

	p->order = NULL;	//空4
	p=h->sort;

	while(p)
	{	printf("%d,",p->val);
		p=p->sort;
	}
	printf("\n\n");

	for (p=h->order;p;p=p->order)
		printf("%d,",p->val);
	printf("\n\n");
}
