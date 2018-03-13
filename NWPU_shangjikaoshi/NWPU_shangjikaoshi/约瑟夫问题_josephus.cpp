#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<stdlib.h>
using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}node, *node_pointer;

/* n为总人数,k为第一个开始报数的人的编号,从1开始,数到m的人出列 */
void JOSEPHUS(int n, int k, int m)
{
	/* p为当前节点，q为辅助节点，指向p的前驱节点*/
	node_pointer p = NULL, q = NULL, pd = NULL;

	/* 建立循环链表 */
	p = (node_pointer)malloc(sizeof(node));
	p->data = 0;
	p->next = p; //一个节点的循环链表
	pd = p;//p指向编号为0的节点
	for (int i = 1; i<n; i++)
	{
		node_pointer t = (node_pointer)malloc(sizeof(node));
		t->data = i;
		t->next = pd->next;
		pd->next = t;
		pd = t; //循环结束后pd指向编号0的节点，t指向编号n-1的节点。
	}

	q = pd; //把当前指针移到第一个报数的人
	while (k--) //第一次从编号为k的人开始报数，所以要跳过前k-1个人。
	{
		q = p;
		p = p->next;
	}
	while (n--) //直到圆桌周围的n个人全部出列
	{
		for (int s = m - 1; s--; q = p, p = p->next); //从1开始报数，报到m的人出列,对应s从m-1到0的变化。
		q->next = p->next; //将报数为m的节点剔除链表
		printf("%d->", p->data);//输出该链表编号
		free(p);
		p = q->next;
	}
}

int main()
{
	JOSEPHUS(7, 0, 3);
	system("pause");
}
//#include<cstdio>  
//int main() {
//	int n, m;
//	while (scanf("%d %d", &n, &m) == 2 && n&&m) {
//		int ans = 0;
//		for (int i = 1; i <= n; ++i) {
//			ans = (ans + m) % i;
//		}
//		printf("总人数:%d 每次出列的人喊的号数:%d 最后一个出列的人的序号:%d\n", n, m, ans + 1);
//	}
//	return 0;
//}
//int winner(int m, int n)
//{
//	int i;
//	int number;
//	if (m <= 0 || n <= 0) {
//		return -1;
//	}
//	number = 0;                        /* 当只有一个人时，编号为0的出圈 */
//	for (i = 2; i <= m; i++) {           /* 循环m-1次将剩下一个人         */
//		number = (number + n % i) % i; /* 这样写易理解，或(number+n)%i  */
//	}
//	return number + 1;                 /* 程序从0编号，返回时应+1       */
//}
//
//int main()
//{
//	cout << winner(6, 3);
//	system("pause");
//}
typedef struct node
{
	int data;
	struct node *next;
}node;
node *create(int n)
{
	node *p = NULL, *head;
	head = (node*)malloc(sizeof(node));
	p = head;
	node *s;
	int i = 1;
	if (0 != n)
	{
		while (i <= n)
		{
			s = (node*)malloc(sizeof(node));
			s->data = i++;
			head->next = s;
			p = s;
		}
		s->next = head->next;
	}
	free(head);
	return s->next;

}
int main()
{
	int n = 41;
	int m = 3;
	int i;
	node *p = create(n);
	node *temp;
	m %= n;

	while (p != p->next)
	{
		for (i = 1; i < m - 1; i++)
		{
			p = p->next;
		}
		printf("%d->", p->next->data);

		temp = p->next;
		p->next = temp->next;
		free(temp);
		p = p->next;
	}
	printf("%d\n", p->data);
	return 0;

}