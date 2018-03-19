#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/* 二叉树的二叉链表结点结构定义 */
typedef  struct BiTNode    /* 结点结构 */
{
	int data;    /* 结点数据 */
	struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
} BiTNode, *BiTree;

/*在二元排序树b中查找x的过程为：
1.若b是空树，则搜索失败，否则：
2.若x等于b的根节点的数据域之值，则查找成功；否则：
3.若x小于b的根节点的数据域之值，则搜索左子树；否则：
4.查找右子树。

/*递归查找二叉排序树T中是否存在key, */
/* 指针f指向T的双亲，其初始调用值为NULL */
/* 若查找成功，则指针p指向该数据元素结点，并返回TRUE */
/* 否则指针p指向查找路径上访问的最后一个结点并返回FALSE */
bool Delete(BiTree *p);
bool SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if (!T)    /*  查找不成功 */
	{
		*p = f;
		return false;
	}
	else if (key == T->data) /*  查找成功 */
	{
		*p = T;
		return true;
	}
	else if (key<T->data)
		return SearchBST(T->lchild, key, T, p);  /*  在左子树中继续查找 */
	else
		return SearchBST(T->rchild, key, T, p);  /*  在右子树中继续查找 */
}

/*  当二叉排序树T中不存在关键字等于key的数据元素时， */
/*  插入key并返回TRUE，否则返回FALSE */
bool InsertBST(BiTree *T, int key)
{
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p)) /* 查找不成功 */
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
			*T = s;            /*  插入s为新的根结点 */
		else if (key<p->data)
			p->lchild = s;    /*  插入s为左孩子 */
		else
			p->rchild = s;  /*  插入s为右孩子 */
		return true;
	}
	else
		return false;  /*  树中已有关键字相同的结点，不再插入 */
}

void zhongxu(BiTree T)
{
	if (T)
	{
		zhongxu(T->lchild);
		cout << T->data<<' ';
		zhongxu(T->rchild);
	}
}
int main()
{
	int i=0;
	int a[100];
	/*for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}*/
	do
	{
		scanf("%d",&a[i++]);
	} while (getchar()!='\n');
	BiTree T = NULL;
	for (int j = 0; j <i ; j++)
	{
		//cout << a[j]<<' ';
		InsertBST(&T, a[j]);
	}
	zhongxu(T);
	system("pause");
	return 0;
}
//int main()
//{
//	int i=0;
//	int a[10] = {9,8,7,6,5,4,3,2,1,0};
//	/*do
//	{
//		cin >> a[i++];
//	} while (getchar() != '\n');*/
//	BiTree T = NULL;
//	for (int j = 0; j < 9; i++)
//	{
//		InsertBST(&T, a[j]);
//	}
//	zhongxu(T);
//	system("pause");
//	return 0;
//}

/* 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点, */
/* 并返回TRUE；否则返回FALSE。 */
bool DeleteBST(BiTree *T, int key)
{
	if (!*T) /* 不存在关键字等于key的数据元素 */
		return false;
	else
	{
		if (key == (*T)->data) /* 找到关键字等于key的数据元素 */
			return Delete(T);
		else if (key<(*T)->data)
			return DeleteBST(&(*T)->lchild, key);
		else
			return DeleteBST(&(*T)->rchild, key);

	}
}

/* 从二叉排序树中删除结点p，并重接它的左或右子树。 */
bool Delete(BiTree *p)
{
	BiTree q, s;
	if ((*p)->rchild == NULL) /* 右子树空则只需重接它的左子树（待删结点是叶子也走此分支) */
	{
		q = *p; *p = (*p)->lchild; free(q);
	}
	else if ((*p)->lchild == NULL) /* 只需重接它的右子树 */
	{
		q = *p; *p = (*p)->rchild; free(q);
	}
	else /* 左右子树均不空 */
	{
		q = *p; s = (*p)->lchild;
		while (s->rchild) /* 转左，然后向右到尽头（找待删结点的前驱） */
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data; /*  s指向被删结点的直接前驱（将被删结点前驱的值取代被删结点的值） */
		if (q != *p)
			q->rchild = s->lchild; /*  重接q的右子树 */
		else
			q->lchild = s->lchild; /*  重接q的左子树 */
		free(s);
	}
	return true;
}
