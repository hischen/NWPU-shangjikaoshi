/*
	根据二叉树的先序和中序序列，设计算法重构出这棵二叉树。（40分）
	已知一棵二叉树的先序遍历序列是ABECDFGHIJ，中序遍历序列是EBCDAFHIGJ，
	请设计一个算法，将这棵二叉树的结构重构出来，
	并且输出它的三种深度优先遍历的结果（即先序、中序和后序序列）。
*/

#include <stdio.h>

typedef struct BiTNode
{
    char e;
    struct BiTNode *lchild,*rchild;
}BiTNode;

/*
	Implement the following parts as ToDo
*/

void preOrderTravse(BiTNode *T1)
{
		/*  ToDo*/
}

void inOrderTravse(BiTNode *T1)
{
		/*  ToDo*/
}

void postOrderTravse(BiTNode *T1)
{
		/*  ToDo*/
}

int CreateBiTree(BiTNode **T1, char *preString, char *inString, int start, int end)
{

    if (start == end) 
    {
		/*  ToDo*/
    }
    else
		{
			/*  ToDo*/
			
			CreateBiTree(&((*T1)->lchild), preString, inString, start, middle);
			CreateBiTree(&((*T1)->rchild) , preString, inString, middle+1, end);
		}
    return 1;
}

main()
{
		/*
		Call CreateBiTree() function
		*/
		CreateBiTree();

		/*
		Call three different Travse functions
		*/
		preOrderTravse();
		inOrderTravse();
		postOrderTravse();

}
