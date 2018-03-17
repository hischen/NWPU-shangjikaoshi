/*
	一个n位正整数（n可以任意大，本次考试n的范围是1~5000）的数字根是指该数字各位数字之和。
	如果和是一个个位数，那么这个数字就是它的数字根，如果和是个两位或多于两位的数字，那么就继续求和直到得到个位数。
	例如：数字24，把2和4相加，得到6，那么6就是24的数字根；
	又比如数字39，把数字3和9相加，得到12，因为12时两位数，所以继续把1和2相加，得到3，于是3就是39的数字根。
	要求：
	使用链表存储输入的数据，并且在计算的过程中使用链表存储中间计算的结果，完成本题目的功能。
	输入：
	输入将包含一列正整数，每行只有一个数字串。当一行中仅有数字0时，表示输入结束。
	输出：
	对于每一个输入的正整数，在单独的一行里输出它的数字根。
	样例输入：
	24
	39
	0
	样例输出：
	6
	3
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	unsigned char bit;
	struct _node *link;
}node;

typedef struct 
{
	node* head;
	int length;
}LinkedList;

int calculateRoot(LinkedList la)
{
	int root=0;
	node *p;
	/* To Do */
	p = la.head;
	while(p->link != NULL)
	{
		root += p->link->bit;
		p = p->link;
	}
	while(root > 9)
	{
		//继续计算
		p = la.head->link;
		p->bit = root % 10;
		p->link->bit = root / 10;
		p->link->link = NULL;
		root = calculateRoot(la);
	}
		
	/* To Do */
	
	return root;
}

LinkedList InputData()
{
	LinkedList la;
	char str[5000];
	char *p;
	int len=0;
	node *temp;

	gets(str);
	la.length=0;
	la.head=(node*)malloc(sizeof(node));
	la.head->bit=0;
	la.head->link=NULL;

	p=str;

	if (*p != '0')
	{
		while (*p != '\0')
		{
			temp = (node*)malloc(sizeof(node));
			temp->bit = (*p) - '0';
			temp->link = la.head->link;
			la.head->link=temp;
			p++;
			la.length++;
		}
	}

	return la;
}

void freeList(LinkedList la)
{
	node *head, *temp;

	head=la.head->link;
	while (head != NULL)
	{
		temp = head;
		head = head->link;
		free(temp);
	}
	free(la.head);

}

void main()
{

	LinkedList la;
	int numberRoot;
	for (;;)
	{
		la=InputData();
		if (la.length == 0)
		{
			freeList(la);
			break;
		}
		numberRoot = calculateRoot(la);
		printf("the root of this number is %d\n",numberRoot);
		freeList(la);
	}
}
