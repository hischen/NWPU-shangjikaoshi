/*
	某皇帝有2m个儿子，现在要从中选出一个做太子，
	皇帝不知道该把那一个皇子立为太子，于是决定用下面的方法来选出太子，
	设每个太子的编号分别1(0)、2、3、…、2m(2m-1)，按顺时针方向站成一个圆圈，
	现在从1(0)号太子开始按顺时针方向数，数到第n(n-1)个人，把他淘汰出局，
	然后从他的下一个人开始上述过程，当第m个人被淘汰时，转变方向继续从1开始数，
	重复上述过程，最后剩下的皇子将被立为太子。现在请你写一个程序，
	计算出几号皇子将被立为太子。
	输入数据：输入两个正整数m n
	输出数据：输出太子的编号
	Sample input
	3 3
	Sample output
	1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* prior;
	struct Node* next;
}sonNode;

sonNode* Create()
{
	sonNode *p;

	if(!(p = (sonNode*)malloc(sizeof(sonNode))))
	{
		printf("Not enough!\n");
		exit(0);
	}

	
	p->data = 0;
	p->prior = p;
	p->next = p;

	return p;

}

void Initiate(sonNode* son, int n)
{
	sonNode *p, *q;
	int k = 0;

	q = son->next;
	
	while(k < n - 1)
	{
		if(!(p = (sonNode*)malloc(sizeof(sonNode))))
		{
			printf("Not enough!\n");
			exit(0);
		}
		p->data = k + 1;
		q->next = p;
		p->prior = q;
		p->next = q;
		q = p;
		k++;
	}
	q->next = son;
	son->prior = q;
}
/*
sonNode* DeleteS(sonNode* son, int m, int n)
{	//顺时针删除
	sonNode *p, *q;
	int i = 1, j = 0;

	p = son;
	while(j < m)
	{
		if(i < n)
		{
			p = p->next;	
			i++;
		}
		else
		{
			p->prior->next = p->next;
			p->next->prior = p->prior;
			q = p;
		//	printf("%d ", q->data);
			p = p->next;
			free(q);
			j++;
			i = 1;
		}
	}

	return p;
}

sonNode* DeleteN(sonNode* son, int m, int n)
{	//逆时针删除
	sonNode *p, *q;
	int i = 1, j = 0;

	p = son;
	while(j < m)
	{
		if(i < n)
		{
			p = p->prior;	
			i++;
		}
		else
		{
			p->prior->next = p->next;
			p->next->prior = p->prior;
			q = p;
		//	printf("%d ", q->data);
			p = p->prior;
			free(q);
			j++;
			i = 1;
		}
	}

	return p;
}
*/
int Delete(sonNode* son, int m, int n)
{
	sonNode *p, *q;
	int i = 1, j = 0, flag = 1;

	p = son;
	while(flag)
	{
		i = 1;
		j = 0;
		while(j < m && flag)
		{
			if(i < n)
			{
				p = p->next;	
				i++;
			}
			else
			{
				p->prior->next = p->next;
				p->next->prior = p->prior;
				q = p;
				p = p->next;
				free(q);
				j++;
				i = 1;			
				if(p->next == p) 
					flag = 0;
			}
		}
	
		i = 1;
		j = 0;
		while(j < m && flag)
		{
			if(i < n)
			{
				p = p->prior;	
				i++;
			}
			else
			{
				p->prior->next = p->next;
				p->next->prior = p->prior;
				q = p;
				p = p->prior;
				free(q);
				j++;
				i = 1;
				if(p->prior == p) 
					flag = 0;		
			}
		}
	}

	return p->data;
}

void main()
{
	sonNode *son, *p;
	unsigned int m, n;

	scanf("%d %d", &m, &n);
	if(m == 0 || n == 0)
	{
		printf("Error!\n");
		exit(0);
	}

	son = Create();
	Initiate(son, 2 * m);
	printf("%d\n", Delete(son, m, n));

//	son = DeleteS(son, m, n);
//	son = DeleteN(son, m, n);

/*
	p = son->next;
	printf("\n%d ", son->data);
	while(p != son)
	{
		printf("%d ", p->data);
		p = p->next;
	}
*/
}