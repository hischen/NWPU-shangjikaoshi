#include<iostream>
#include<malloc.h>
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

using namespace std;
typedef struct Node {
	int data;
	Node *next;
}Node;
Node* createcycle(int n)
{
	Node* head = (Node *)malloc(sizeof(Node));
	head->data = 1;
	head->next = NULL;
	Node* p = head;
	for (int i = 2; i <= n; i++)
	{
		Node *q = (Node*)malloc(sizeof(Node));
		q->data = i;
		q->next = NULL;
		p->next = q;

		p = q;
	}
	p->next=head;
	return p;
}
Node*countnode(Node* p, int k)
{
	Node* pre = p;
	for (int i = 0; i < k; i++)
	{
		pre = p;
		p = p->next;
	}
	if (pre == p)
	{
		printf("%d\n", p->data);
		free(p);
		return NULL;
	}
	else 
	{
		printf("%d->", p->data);
		pre->next = p->next;
		free(p);
		return pre;
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	Node * head = createcycle(n);
	//cout << head->data;
	for (int i = 0; i < n; i++)
	{
		head = countnode(head, k);
	}
	system("pause");
	return 0;
}

/*https://www.zhihu.com/question/29899488 */

//struct Node {
//	int data;
//	Node* next;
//};
//
//Node* CreateCycle(int n) {
//	Node* head = (Node*)malloc(sizeof(Node));
//	head->data = 1;
//	head->next = NULL;
//	Node* p = head;
//	for (int i = 2; i <= n; i++) {
//		Node* q = (Node*)malloc(sizeof(Node));
//		q->data = i;
//		q->next = NULL;
//
//		p->next = q;
//		p = q;
//	}
//	p->next = head;
//	return p;
//}
//
//Node* CountNode(Node* p, int k) {
//	assert(k > 0);
//	Node* pre = p;
//	for (int i = 0; i<k; i++) {
//		pre = p;
//		p = p->next;
//	}
//	if (pre == p) {
//		printf("%d\n", p->data);
//		free(p);
//		return NULL;
//	}
//	else {
//		printf("%d ", p->data);
//		pre->next = p->next;
//		free(p);
//		return pre;
//	}
//}
//
//int main() {
//	int n, k;
//	scanf("%d %d", &n, &k);
//	Node* head = CreateCycle(n);
//	for (int i = 0; i<n; i++) {
//		head = CountNode(head, k);
//	}
//	return 0;
//}

